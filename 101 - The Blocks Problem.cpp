#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
void putBack(const int target, vector<int> *blocks, int *position){
    const int pos=position[target];
    vector<int>::iterator start=find(blocks[pos].begin(), blocks[pos].end(), target)+1;
    for(vector<int>::iterator it=start;it!=blocks[pos].end();++it){
        blocks[*it].push_back(*it);
        position[*it]=*it;
    }
    blocks[pos].erase(start, blocks[pos].end());
}
int main(){
    int n;
    while(cin>>n){
        vector<int> blocks[n];
        int position[n];
        for(int i=0;i<n;++i){
            blocks[i].clear();
            blocks[i].push_back(i);
            position[i]=i;
        }
        while(true){
            string operation;
            cin>>operation;
            if(operation=="quit"){
                break;
            }
            int a, b;
            string function;
            cin>>a>>function>>b;
            if(position[a]==position[b]){
                continue;
            }
            if(function=="onto"){
                putBack(b, blocks, position);
            }
            if(operation=="move"){
                putBack(a, blocks, position);
                blocks[position[a]].pop_back();
                blocks[position[b]].push_back(a);
                position[a]=position[b];
            }else{
                const int posA=position[a], posB=position[b];
                vector<int>::iterator start=find(blocks[posA].begin(), blocks[posA].end(), a);
                for(vector<int>::iterator it=start;it!=blocks[posA].end();++it){
                    blocks[posB].push_back(*it);
                    position[*it]=posB;
                }
                blocks[posA].erase(start, blocks[posA].end());
            }
        }
        for(int i=0;i<n;++i){
            cout<<i<<':';
            for(int j=0;j<blocks[i].size();++j){
                cout<<' '<<blocks[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}