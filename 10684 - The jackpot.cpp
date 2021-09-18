#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    while(true){
        int n;
        cin>>n;
        if(n==0){
            break;
        }
        int num[n+1];
        num[0]=0;
        for(int i=1;i<=n;++i){
            cin>>num[i];
        }
        for(int i=1;i<=n;++i){
            num[i]+=num[i-1];
        }
        int M=INT_MIN;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<=n;++j){
                M=max(M, num[j]-num[i]);
            }
        }
        if(M<=0){
            cout<<"Losing streak."<<endl;
        }else{
            cout<<"The maximum winning streak is "<<M<<"."<<endl;
        }
    }
    return 0;
}