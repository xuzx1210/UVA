#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
void push(int len, int i, string &word, vector<string> &dict){
    if(i==len){
        dict.push_back(word);
        return;
    }
    if(i==0){
        for(char c='a';c<='z'-len+1;++c){
            word[i]=c;
            push(len, i+1, word, dict);
        }
    }else{
        for(char c='a';c<='z'-len+i+1;++c){
            if(c<=word[i-1]){
                continue;
            }
            word[i]=c;
            push(len, i+1, word, dict);
        }
    }
}
bool valid(string &word){
    if(word.length()>5){
        return false;
    }
    for(int i=1;i<word.length();++i){
        if(word[i]<=word[i-1]){
            return false;
        }
    }
    return true;
}
int main(){
    vector<string> dict;
    for(int len=1;len<=5;++len){
        string word(len, ' ');
        push(len, 0, word, dict);
    }
    string word;
    while(cin>>word){
        if(valid(word)){
            vector<string>::iterator it=find(dict.begin(), dict.end(), word);
            cout<<it-dict.begin()+1<<endl;
        }else{
            cout<<"0"<<endl;
        }
    }
    return 0;
}