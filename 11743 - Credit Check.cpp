#include<iostream>
#include<sstream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int t=0;t<n;++t){
        char input;
        int number[16];
        for(int i=0;i<16;++i){
            cin>>input;
            number[i]=input-'0';
        }
        stringstream ss;
        ss.clear();
        for(int i=0;i<16;i+=2){
            ss<<number[i]*2;
        }
        for(int i=1;i<16;i+=2){
            ss<<number[i];
        }
        int sum=0;
        while(ss>>input){
            sum+=(input-'0');
        }
        cout<<(sum%10?"Invalid":"Valid")<<endl;
    }
    return 0;
}