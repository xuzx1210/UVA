#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    string line;
    vector<string> sentence;
    while(getline(cin, line)){
        sentence.push_back(line);
    }
    int m=0;
    for(int i=0;i<sentence.size();++i){
        if(sentence[i].length()>m){
            m=sentence[i].length();
        }
    }
    for(int i=0;i<m;++i){
        for(int j=sentence.size()-1;j>=0;--j){
            if(i>=sentence[j].length()){
                cout<<" ";
            }else{
                cout<<sentence[j][i];
            }
        }
        cout<<endl;
    }
    return 0;
}