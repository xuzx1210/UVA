#include<iostream>
using namespace std;
int main(){
    while(true){
        int n;
        cin>>n;
        if(n==0){
            break;
        }
        bool bit[32];
        for(int i=0;i<32;++i){
            bit[i]=n&1;
            n>>=1;
        }
        int parity=0;
        for(int i=0;i<32;++i){
            if(bit[i]){
                ++parity;
            }
        }
        cout<<"The parity of ";
        int start;
        for(int i=31;i>=0;--i){
            if(bit[i]){
                start=i;
                break;
            }
        }
        for(int i=start;i>=0;--i){
            cout<<(bit[i]?"1":"0");
        }
        cout<<" is "<<parity<<" (mod 2)."<<endl;
    }
    return 0;
}