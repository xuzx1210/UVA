#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
using namespace std;
int main(){
    string num;
    while(cin>>num){
        if(num[0]=='-'){
            break;
        }
        bool printed=false;
        if(num.length()>2){
            if(num[1]=='x'){
                printed=true;
                stringstream ss(num);
                int h;
                ss>>hex>>h;
                cout<<dec<<h<<endl;
            }
        }
        if(!printed){
            stringstream ss(num);
            int d;
            ss>>dec>>d;
            cout<<"0x"<<hex<<uppercase<<d<<endl;
        }
    }
    return 0;
}