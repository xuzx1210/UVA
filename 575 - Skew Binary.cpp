#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    while(true){
        string skewBinary;
        cin>>skewBinary;
        if(skewBinary=="0"){
            break;
        }
        reverse(skewBinary.begin(), skewBinary.end());
        int decimal=0;
        for(int i=0;i<skewBinary.length();++i){
            decimal+=(skewBinary[i]-'0')*((2<<i)-1);
        }
        cout<<decimal<<endl;
    }
    return 0;
}