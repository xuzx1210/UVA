#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int t=0;t<n;++t){
        int a, b;
        cin>>a>>b;
        cout<<"Case "<<t+1<<": ";
        if(a==b){
            cout<<(a&1?a:0)<<endl;
            continue;
        }
        if((a&1)==0){
            ++a;
        }
        if((b&1)==0){
            --b;
        }
        cout<<(((a+b)*(b-a+2))>>2)<<endl;
    }
    return 0;
}