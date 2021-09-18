#include<iostream>
using namespace std;
int main(){
    while(true){
        unsigned int n, k;
        cin>>n>>k;
        if(n==0 && k==0){
            break;
        }
        k=min(k, n-k);
        unsigned long long int result=1;
        for(int i=1, j=n-k+1;i<=k;++i, ++j){
            result*=j;
            result/=i;
        }
        cout<<result<<endl;
    }
    return 0;
}