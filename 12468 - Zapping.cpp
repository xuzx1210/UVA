#include<iostream>
using namespace std;
int main(){
    while(true){
        int a, b;
        cin>>a>>b;
        if(a==-1 || b==-1){
            break;
        }
        int diff=a>b?a-b:b-a;
        cout<<(diff>50?100-diff:diff)<<endl;
    }
    return 0;
}