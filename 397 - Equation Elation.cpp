#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
int main(){
    string line;
    while(getline(cin, line)){
        int equ;
        for(int i=0;i<line.length();++i){
            if(line[i]=='='){
                equ=i;
                break;
            }
        }
        string sentence(line, 0, equ), identifier(line, equ+1, line.length()-equ+2);
        stringstream sss;
        sss<<sentence;
        vector<int> num;
        vector<char> op;
        int tmpint;
        char tmpchar;
        sss>>tmpint;
        num.push_back(tmpint);
        while(sss>>tmpchar){
            op.push_back(tmpchar);
            sss>>tmpint;
            num.push_back(tmpint);
        }
        stringstream ssi;
        ssi<<identifier;
        string variable;
        ssi>>variable;
        for(int i=0;i<op.size();++i){
            cout<<num[i]<<" "<<op[i]<<" ";
        }
        cout<<num[op.size()]<<" = "<<variable<<endl;
        for(int i=0;i<op.size();++i){
            if(op[i]=='*' || op[i]=='/'){
                if(op[i]=='*'){
                    num[i]*=num[i+1];
                }else{
                    num[i]/=num[i+1];
                }
                num.erase(num.begin()+i+1);
                op.erase(op.begin()+i);
                --i;
                for(int j=0;j<op.size();++j){
                    cout<<num[j]<<" "<<op[j]<<" ";
                }
                cout<<num[op.size()]<<" = "<<variable<<endl;
            }
        }
        int len=op.size();
        for(int i=0;i<len;++i){
            if(op[i]=='+'){
                num[i+1]+=num[i];
            }else{
                num[i+1]=num[i]-num[i+1];
            }
            cout<<num[i+1];
            for(int j=i+1;j<len;++j){
                cout<<" "<<op[j]<<" "<<num[j+1];
            }
            cout<<" = "<<variable<<endl;
        }
        cout<<endl;
    }
    return 0;
}