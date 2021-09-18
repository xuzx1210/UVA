#include<iostream>
typedef long long int ll;
using namespace std;
int main(){
    ll wall[50]={1, 2};
    for(int i=2;i<50;++i){
        wall[i]=wall[i-1]+wall[i-2];
    }
    while(true){
        int n;
        cin>>n;
        if(n==0){
            break;
        }
        cout<<wall[n-1]<<endl;
    }
    return 0;
}