#include<iostream>
#include<cctype>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
int main(){
    int k, e, s=1;
    while(cin>>k>>e){
        vector<string> excuse;
        for(int i=0;i<k;++i){
            string tmp;
            cin>>tmp;
            for(int j=0;j<tmp.length();++j){
                tmp[j]=tolower(tmp[j]);
            }
            excuse.push_back(tmp);
        }
        int excuseCount[e];
        for(int i=0;i<e;++i){
            excuseCount[i]=0;
        }
        string line;
        vector<string> excuseLine;
        getline(cin, line);
        for(int i=0;i<e;++i){
            getline(cin, line);
            excuseLine.push_back(line);
            for(int j=0;j<line.length();++j){
                if(isalpha(line[j])){
                    line[j]=tolower(line[j]);
                }else{
                    line[j]=' ';
                }
            }
            stringstream ss;
            ss<<line;
            string tmp;
            while(ss>>tmp){
                for(int j=0;j<excuse.size();++j){
                    if(tmp==excuse[j]){
                        ++excuseCount[i];
                        break;
                    }
                }
            }
        }
        int max=0;
        for(int i=0;i<e;++i){
            if(excuseCount[i]>max){
                max=excuseCount[i];
            }
        }
        cout<<"Excuse Set #"<<s<<endl;
        for(int i=0;i<e;++i){
            if(excuseCount[i]==max){
                cout<<excuseLine[i]<<endl;
            }
        }
        cout<<endl;
        ++s;
    }
    return 0;
}