#include<iostream>
#include<string>
using namespace std;
int main(){
    while(true){
        string number;
        cin>>number;
        if(number=="0"){
            break;
        }
        int remainder=0;
        for(int i=0;i<number.length();++i){
            remainder=(remainder*10+number[i]-'0')%17;
        }
        cout<<(remainder==0)<<endl;
    }
    return 0;
}