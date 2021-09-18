#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<pair<int, int>> num;
    int tmp;
    while(cin>>tmp){
        bool found=false;
        for(int i=0;i<num.size();++i){
            if(num[i].first==tmp){
                ++num[i].second;
                found=true;
                break;
            }
        }
        if(!found){
            num.push_back({tmp, 1});
        }
    }
    for(int i=0;i<num.size();++i){
        cout<<num[i].first<<" "<<num[i].second<<endl;
    }
    return 0;
}