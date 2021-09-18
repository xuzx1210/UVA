#include<iostream>
#include<string>
#include<sstream>
#include<climits>
using namespace std;
int main(){
    string A, B;
    double a, b;
    char op;
    while(cin>>A>>op>>B){
        stringstream ss;
        ss<<A;
        ss>>a;
        ss.clear();
        ss<<B;
        ss>>b;
        cout<<A<<" "<<op<<" "<<B<<endl;
        if(a>INT_MAX){
            cout<<"first number too big"<<endl;
        }
        if(b>INT_MAX){
            cout<<"second number too big"<<endl;
        }
        if(op=='+'){
            if(a+b>INT_MAX){
                cout<<"result too big"<<endl;
            }
        }else{
            if(a*b>INT_MAX){
                cout<<"result too big"<<endl;
            }
        }
    }
    return 0;
}