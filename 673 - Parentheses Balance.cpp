#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
    int n;
    cin>>n;
    string line;
    getline(cin, line);
    for(int t=0;t<n;++t){
        getline(cin, line);
        stack<char> check;
        while(!check.empty()){
            check.pop();
        }
        bool error=false;
        for(int i=0;i<line.length();++i){
            char cur=line[i];
            if(cur=='(' || cur=='['){
                check.push(cur);
            }else{
                if(check.empty()){
                    error=true;
                    break;
                }
                char top=check.top();
                if((cur==')' && top=='[') || (cur==']' && top=='(')){
                    error=true;
                    break;
                }
                check.pop();
            }
        }
        if(!check.empty()){
            error=true;
        }
        cout<<(error?"No":"Yes")<<endl;
    }
    return 0;
}