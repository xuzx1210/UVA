#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    while(true){
        string a, b;
        cin>>a>>b;
        if(a=="0" && b=="0"){
            break;
        }
        int len=max(a.length(), b.length());
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        a.insert(a.end(), len-a.length(), '0');
        b.insert(b.end(), len-b.length(), '0');
        bool carry=false;
        int operation=0;
        for(int i=0;i<len;++i){
            carry=((a[i]-'0')+(b[i]-'0')+(carry?1:0))/10;
            operation+=(carry?1:0);
        }
        if(operation==0){
            cout<<"No carry operation."<<endl;
        }else if(operation==1){
            cout<<"1 carry operation."<<endl;
        }else{
            cout<<operation<<" carry operations."<<endl;
        }
    }
    return 0;
}