#include<iostream>
using namespace std;
int f(int n){
    int sum=0;
    while(n){
        sum+=(n%10);
        n/=10;
    }
    return sum;
}
int g(int n){
    while(n>9){
        n=f(n);
    }
    return n;
}
int main(){
    while(true){
        int n;
        cin>>n;
        if(n==0){
            break;
        }
        cout<<g(n)<<endl;
    }
}