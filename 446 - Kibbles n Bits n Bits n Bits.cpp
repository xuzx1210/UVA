#include<iostream>
#include<cstdio>
using namespace std;
void print_binary(int num){
    for(int mask=1<<12;mask!=0;mask>>=1){
        if(num&mask){
            cout<<"1";
        }else{
            cout<<"0";
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int a, b;
        char op;
        scanf("%x %c %x", &a, &op, &b);
        print_binary(a);
        cout<<" "<<op<<" ";
        print_binary(b);
        cout<<" = ";
        if(op=='+'){
            cout<<a+b<<endl;
        }else{
            cout<<a-b<<endl;
        }
    }
    return 0;
}