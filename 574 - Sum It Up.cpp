#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void print(vector<int> &used){
    cout<<used[0];
    for(int i=1;i<used.size();++i){
        cout<<"+"<<used[i];
    }
    cout<<endl;
}
void dfs(vector<int> &num, vector<int> &used, vector<vector<int>> &record, const int depth, const int remain, int &counter){
    if(remain==0){
        if(find(record.begin(), record.end(), used)==record.end()){
            print(used);
            record.push_back(used);
            ++counter;
        }
        return;
    }
    if(depth==num.size()){
        return;
    }
    if(num[depth]<=remain){
        used.push_back(num[depth]);
        dfs(num, used, record, depth+1, remain-num[depth], counter);
        used.pop_back();
    }
    dfs(num, used, record, depth+1, remain, counter);
}
int main(){
    while(true){
        int t, n;
        cin>>t>>n;
        if(n==0){
            break;
        }
        vector<int> num;
        num.clear();
        for(int i=0;i<n;++i){
            int tmp;
            cin>>tmp;
            num.push_back(tmp);
        }
        vector<int> used;
        used.clear();
        vector<vector<int>> record;
        record.clear();
        int counter=0;
        cout<<"Sums of "<<t<<":"<<endl;
        dfs(num, used, record, 0, t, counter);
        if(counter==0){
            cout<<"NONE"<<endl;
        }
    }
    return 0;
}