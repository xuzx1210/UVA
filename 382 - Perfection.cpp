#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
    cout<<"PERFECTION OUTPUT"<<endl;
    int n;
    cin>>n;
    while(n){
        int sum=1, s=floor(sqrt(n));
        for(int i=2;i*i<=n;++i){
            if((n%i)==0){
                sum+=(i+n/i);
            }
        }
        if(s*s==n){
            sum-=s;
        }
        cout<<setw(5)<<n<<"  ";
        if(sum<n){
            cout<<"DEFICIENT"<<endl;
        }else if(sum>n){
            cout<<"ABUNDANT"<<endl;
        }else{
            cout<<"PERFECT"<<endl;
        }
        cin>>n;
    }
    cout<<"END OF OUTPUT"<<endl;
    return 0;
}