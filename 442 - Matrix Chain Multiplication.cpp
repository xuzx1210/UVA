#include<iostream>
#include<string>
#include<stack>
#include<map>
using namespace std;
int main(){
    int n;
    cin>>n;
    map<char, pair<int, int>> m;
    for(int i=0;i<n;++i){
        char c;
        int x, y;
        cin>>c>>x>>y;
        m[c]={x, y};
    }
    string line;
    while(cin>>line){
        int cost=0;
        bool legal=true;
        stack<pair<int, int>> s;
        for(int i=0;i<line.length();++i){
            if(line[i]=='('){
                continue;
            }
            if(line[i]==')'){
                pair<int, int> a, b;
                b=s.top();
                s.pop();
                a=s.top();
                s.pop();
                if(a.second!=b.first){
                    legal=false;
                    break;
                }
                cost+=(a.first*a.second*b.second);
                s.push({a.first, b.second});
            }else{
                s.push(m[line[i]]);
            }
        }
        if(legal){
            cout<<cost<<endl;
        }else{
            cout<<"error"<<endl;
        }
    }
    return 0;
}