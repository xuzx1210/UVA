#include<iostream>
using namespace std;
int main(){
    int a;
    while(cin>>a){
        int p=1, digits=1;
        while(p%a){
            p=(p%a)*10+1;
            ++digits;
        }
        cout<<digits<<endl;
    }
    return 0;
}