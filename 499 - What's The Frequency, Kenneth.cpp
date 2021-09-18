#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<algorithm>
using namespace std;
int main(){
    string line;
    while(getline(cin, line)){
        vector<pair<char, int>> record;
        for(int i=0;i<line.length();++i){
            if(isalpha(line[i])){
                bool found=false;
                for(int j=0;j<record.size();++j){
                    if(record[j].first==line[i]){
                        ++record[j].second;
                        found=true;
                        break;
                    }
                }
                if(!found){
                    record.push_back({line[i], 1});
                }
            }
        }
        int m=0;
        for(int i=0;i<record.size();++i){
            if(record[i].second>m){
                m=record[i].second;
            }
        }
        vector<char> output;
        for(int i=0;i<record.size();++i){
            if(record[i].second==m){
                output.push_back(record[i].first);
            }
        }
        sort(output.begin(), output.end());
        for(int i=0;i<output.size();++i){
            cout<<output[i];
        }
        cout<<" "<<m<<endl;
    }
    return 0;
}