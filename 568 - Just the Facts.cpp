#include<iostream>
#include<iomanip>
typedef unsigned long long int ull;
using namespace std;
int main(){
    ull tail[10001];
    tail[0]=0;
    tail[1]=1;
    for(int i=2;i<=10000;++i){
        tail[i]=tail[i-1]*i;
        while((tail[i]%10)==0){
            tail[i]/=10;
        }
        tail[i]%=1000000000;
    }
    int n;
    while(cin>>n){
        cout<<setw(5)<<n<<" -> "<<(tail[n]%10)<<endl;
    }
    return 0;
}