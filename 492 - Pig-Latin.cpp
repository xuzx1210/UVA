#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<algorithm>
using namespace std;
void print(vector<char> &word, vector<char> &vowel){
    if(count(vowel.begin(), vowel.end(), tolower(word[0]))){
        for(int i=0;i<word.size();++i){
            cout<<word[i];
        }
    }else{
        for(int i=1;i<word.size();++i){
            cout<<word[i];
        }
        cout<<word[0];
    }
    cout<<"ay";
}
int main(){
    vector<char> vowel;
    vowel.push_back('a');
    vowel.push_back('e');
    vowel.push_back('i');
    vowel.push_back('o');
    vowel.push_back('u');
    string line;
    while(getline(cin, line)){
        line.insert(line.end(), ' ');
        bool last=false;
        vector<char> word;
        for(int i=0;i<line.length();++i){
            if(isalpha(line[i])){
                word.push_back(line[i]);
                last=true;
            }else{
                if(last){
                    print(word, vowel);
                    word.clear();
                }
                if(i!=line.length()-1){
                    cout<<line[i];
                }
                last=false;
            }
        }
        cout<<endl;
    }
    return 0;
}