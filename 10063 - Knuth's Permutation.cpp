#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
void permute(vector<char> &cur, stack<char> &remain){
    if(remain.empty()){
        for(int i=0;i<cur.size();++i){
            cout<<cur[i];
        }
        cout<<endl;
        return;
    }
    const char c=remain.top();
    remain.pop();
    for(int i=0;i<cur.size();++i){
        cur.insert(cur.begin()+i, c);
        permute(cur, remain);
        cur.erase(cur.begin()+i);
    }
    cur.push_back(c);
    permute(cur, remain);
    cur.erase(cur.begin()+cur.size()-1);
    remain.push(c);
}
int main(){
    string word;
    int t=0;
    while(cin>>word){
        if(t){
            cout<<endl;
        }
        stack<char> remain;
        while(!remain.empty()){
            remain.pop();
        }
        for(int i=word.length()-1;i>=0;--i){
            remain.push(word[i]);
        }
        vector<char> cur;
        cur.clear();
        permute(cur, remain);
        ++t;
    }
    return 0;
}