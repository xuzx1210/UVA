#include<iostream>
typedef unsigned long long int ull;
using namespace std;
int main(){
    ull a, b;
    while(cin>>a>>b){
        cout<<(a>b?a-b:b-a)<<endl;
    }
    return 0;
}