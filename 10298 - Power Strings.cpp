#include<iostream>
#include<string>
using namespace std;
int main(){
    while(true){
        string s;
        cin>>s;
        if(s=="."){
            break;
        }
        for(int len=1;len<=s.length();++len){
            if(s.length()%len!=0){
                continue;
            }
            bool different=false;
            for(int i=len;i<s.length();++i){
                if(s[i]!=s[i%len]){
                    different=true;
                }
            }
            if(!different){
                cout<<s.length()/len<<endl;
                break;
            }
        }
    }
    return 0;
}