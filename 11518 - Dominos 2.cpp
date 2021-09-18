#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int testcase;
    cin>>testcase;
    for(int t=0;t<testcase;++t){
        int n, m, l;
        cin>>n>>m>>l;
        vector<int> knock[n];
        bool down[n];
        for(int i=0;i<n;++i){
            knock[i].clear();
            down[i]=false;
        }
        for(int i=0;i<m;++i){
            int x, y;
            cin>>x>>y;
            knock[x-1].push_back(y-1);
        }
        queue<int> bfs;
        while(!bfs.empty()){
            bfs.pop();
        }
        int count=0;
        for(int i=0;i<l;++i){
            int z;
            cin>>z;
            if(!down[z-1]){
                bfs.push(z-1);
                down[z-1]=true;
                ++count;
            }
        }
        while(!bfs.empty()){
            int cur=bfs.front();
            bfs.pop();
            for(int i=0;i<knock[cur].size();++i){
                int next=knock[cur][i];
                if(!down[next]){
                    bfs.push(next);
                    down[next]=true;
                    ++count;
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}