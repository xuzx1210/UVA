#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main(){
    string line;
    while(getline(cin, line)){
        for(int i=0;i<line.length();++i){
            if(isdigit(line[i])){
                int num=0;
                while(isdigit(line[i])){
                    num+=(line[i]-'0');
                    ++i;
                }
                if(line[i]=='b'){
                    line[i]=' ';
                }
                for(int j=0;j<num;++j){
                    cout<<line[i];
                }
            }
            if(line[i]=='!'){
                cout<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}