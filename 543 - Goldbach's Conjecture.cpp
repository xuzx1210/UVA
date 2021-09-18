#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    bool prime[1000000];
    for(int i=2;i<1000000;++i){
        prime[i]=true;
    }
    for(int i=2;i<1000000;++i){
        if(prime[i]){
            for(int j=i<<1;j<1000000;j+=i){
                prime[j]=false;
            }
        }
    }
    while(true){
        int n;
        cin>>n;
        if(n==0){
            break;
        }
        bool divisible=false;
        for(int i=2;i<=n>>1;++i){
            if(prime[i]){
                if(prime[n-i]){
                    cout<<n<<" = "<<i<<" + "<<n-i<<endl;
                    divisible=true;
                    break;
                }
            }
        }
        if(!divisible){
            cout<<"Goldbach's conjecture is wrong."<<endl;
        }
    }
    return 0;
}