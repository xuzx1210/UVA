#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
class state{
public:
    state(){
        node={0, 0};
        path.clear();
    }
    pair<int, int> node;
    vector<string> path;
};
int main(){
    int ca, cb, n;
    while(cin>>ca>>cb>>n){
        state init;
        queue<state> next;
        while(!next.empty()){
            next.pop();
        }
        next.push(init);
        vector<pair<int, int>> visited;
        visited.clear();
        visited.push_back({0, 0});
        while(true){
            state cur=next.front();
            if(cur.node.second==n){
                for(int i=0;i<cur.path.size();++i){
                    cout<<cur.path[i]<<endl;
                }
                cout<<"success"<<endl;
                break;
            }
            next.pop();

            state tmp=cur;
            tmp.node.first=ca;
            if(find(visited.begin(), visited.end(), tmp.node)==visited.end()){
                tmp.path.push_back("fill A");
                next.push(tmp);
                visited.push_back(tmp.node);
            }

            tmp=cur;
            tmp.node.second=cb;
            if(find(visited.begin(), visited.end(), tmp.node)==visited.end()){
                tmp.path.push_back("fill B");
                next.push(tmp);
                visited.push_back(tmp.node);
            }

            tmp=cur;
            tmp.node.first=0;
            if(find(visited.begin(), visited.end(), tmp.node)==visited.end()){
                tmp.path.push_back("empty A");
                next.push(tmp);
                visited.push_back(tmp.node);
            }
            
            tmp=cur;
            tmp.node.second=0;
            if(find(visited.begin(), visited.end(), tmp.node)==visited.end()){
                tmp.path.push_back("empty B");
                next.push(tmp);
                visited.push_back(tmp.node);
            }

            tmp=cur;
            int flow=min(tmp.node.first, cb-tmp.node.second);
            tmp.node.first-=flow;
            tmp.node.second+=flow;
            if(find(visited.begin(), visited.end(), tmp.node)==visited.end()){
                tmp.path.push_back("pour A B");
                next.push(tmp);
                visited.push_back(tmp.node);
            }

            tmp=cur;
            flow=min(ca-tmp.node.first, tmp.node.second);
            tmp.node.first+=flow;
            tmp.node.second-=flow;
            if(find(visited.begin(), visited.end(), tmp.node)==visited.end()){
                tmp.path.push_back("pour B A");
                next.push(tmp);
                visited.push_back(tmp.node);
            }
        }
    }
    return 0;
}