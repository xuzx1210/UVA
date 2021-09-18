#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void dfs(const int length, const int target, const int depth, vector<int> &rods, bool &found){
    if(depth==rods.size()){
        if(length==target){
            found=true;
        }
        return;
    }
    if(length==target){
        found=true;
        return;
    }
    if(length>target){
        return;
    }
    dfs(length+rods[depth], target, depth+1, rods, found);
    if(found){
        return;
    }
    dfs(length, target, depth+1, rods, found);
}
int main(){
    int testcases;
    cin>>testcases;
    for(int testcase=0;testcase<testcases;++testcase){
        int target, p;
        cin>>target>>p;
        int rod[p];
        vector<int> rods;
        rods.clear();
        for(int i=0;i<p;++i){
            cin>>rod[i];
            if(rod[i]<=target){
                rods.push_back(rod[i]);
            }
        }
        sort(rods.begin(), rods.end());
        reverse(rods.begin(), rods.end());
        bool found=false;
        dfs(0, target, 0, rods, found);
        cout<<(found?"YES":"NO")<<endl;
    }
    return 0;
}