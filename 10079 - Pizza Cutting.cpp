#include<iostream>
typedef long long int ll;
using namespace std;
int main(){
    while(true){
        ll n;
        cin>>n;
        if(n<0){
            break;
        }
        cout<<1+(((n+1)*n)>>1)<<endl;
    }
    return 0;
}