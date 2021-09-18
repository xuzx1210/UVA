#include<iostream>
#include<string>
using namespace std;
int main(){
    int t=0;
    while(true){
        string word;
        cin>>word;
        if(word=="#"){
            break;
        }
        cout<<"Case "<<++t<<": ";
        if(word=="HELLO"){
            cout<<"ENGLISH"<<endl;
        }else if(word=="HOLA"){
            cout<<"SPANISH"<<endl;
        }else if(word=="HALLO"){
            cout<<"GERMAN"<<endl;
        }else if(word=="BONJOUR"){
            cout<<"FRENCH"<<endl;
        }else if(word=="CIAO"){
            cout<<"ITALIAN"<<endl;
        }else if(word=="ZDRAVSTVUJTE"){
            cout<<"RUSSIAN"<<endl;
        }else{
            cout<<"UNKNOWN"<<endl;
        }
    }
    return 0;
}