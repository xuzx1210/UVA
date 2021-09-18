#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int time=0, neighbors;
    int map[20][20];
    while(cin>>neighbors){
        for(int i=0;i<20;++i){
            for(int j=0;j<20;++j){
                map[i][j]=20;
            }
        }
        for(int i=0;i<20;++i){
            map[i][i]=0;
        }
        for(int i=0;i<neighbors;++i){
            int destination;
            cin>>destination;
            map[0][destination-1]=1;
            map[destination-1][0]=1;
        }
        for(int country=1;country<19;++country){
            cin>>neighbors;
            for(int i=0;i<neighbors;++i){
                int destination;
                cin>>destination;
                map[country][destination-1]=1;
                map[destination-1][country]=1;
            }
        }
        int n;
        cin>>n;
        cout<<"Test Set #"<<++time<<endl;
        for(int testCase=0;testCase<n;++testCase){
            int source, destination;
            cin>>source>>destination;
            cout<<setw(2)<<source--<<" to "<<setw(2)<<destination--<<": ";
            int move[20];
            for(int i=0;i<20;++i){
                move[i]=map[source][i];
            }
            vector<int> visited;
            visited.clear();
            int cur=source;
            for(int i=0;i<20;++i){
                if(cur==destination){
                    break;
                }
                visited.push_back(cur);
                for(int j=0;j<20;++j){
                    move[j]=min(move[j], move[cur]+map[cur][j]);
                }
                int m=20;
                for(int j=0;j<20;++j){
                    if(find(visited.begin(), visited.end(), j)==visited.end()){
                        if(move[j]<m){
                            m=move[j];
                            cur=j;
                        }
                    }
                }
            }
            cout<<move[cur]<<endl;
        }
        cout<<endl;
    }
    return 0;
}