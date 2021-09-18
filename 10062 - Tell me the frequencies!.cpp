#include<iostream>
#include<string>
#include<vector>
using namespace std;
void insert(int index, int value, vector<pair<int, int>> &result){
    bool inserted=false;
    for(int i=0;i<result.size();++i){
        if(value<result[i].second || (value==result[i].second && index>result[i].first)){
            result.insert(result.begin()+i, {index, value});
            inserted=true;
            break;
        }
    }
    if(!inserted){
        result.push_back({index, value});
    }
}
int main(){
    string line;
    int t=0;
    while(getline(cin, line)){
        if(t++){
            cout<<endl;
        }
        int ascii[128];
        for(int i=0;i<128;++i){
            ascii[i]=0;
        }
        for(int i=0;i<line.length();++i){
            ++ascii[line[i]];
        }
        vector<pair<int, int>> result;
        for(int i=0;i<128;++i){
            if(ascii[i]){
                insert(i, ascii[i], result);
            }
        }
        for(int i=0;i<result.size();++i){
            cout<<result[i].first<<' '<<result[i].second<<endl;
        }
    }
    return 0;
}