#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int step, mod;
    while(cin>>step>>mod){
        bool use[mod];
        for(int i=0;i<mod;++i){
            use[i]=false;
        }
        int count=0;
        for(int seed=0;!use[seed];seed=(seed+step)%mod){
            use[seed]=true;
            ++count;
        }
        cout<<setw(10)<<step<<setw(10)<<mod<<"    ";
        if(count==mod){
            cout<<"Good Choice"<<endl<<endl;
        }else{
            cout<<"Bad Choice"<<endl<<endl;
        }
    }
    return 0;
}