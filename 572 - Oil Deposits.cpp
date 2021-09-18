#include<iostream>
#include<queue>
using namespace std;
int main(){
    while(true){
        int m, n;
        cin>>m>>n;
        if(m==0){
            break;
        }
        int deposit=0;
        bool oil[m][n], visited[m][n];
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                char tmp;
                cin>>tmp;
                oil[i][j]=(tmp=='@');
                visited[i][j]=false;
            }
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(!oil[i][j]){
                    continue;
                }
                ++deposit;
                queue<pair<int, int>> next;
                while(!next.empty()){
                    next.pop();
                }
                next.push({i, j});
                visited[i][j]=true;
                while(!next.empty()){
                    pair<int, int> cur=next.front();
                    next.pop();
                    for(int a=-1;a<=1;++a){
                        int x=cur.first+a;
                        if(x<0 || x>=m){
                            continue;
                        }
                        for(int b=-1;b<=1;++b){
                            int y=cur.second+b;
                            if(y<0 || y>=n){
                                continue;
                            }
                            if(oil[x][y] && !visited[x][y]){
                                next.push({x, y});
                                visited[x][y]=true;
                                oil[x][y]=false;
                            }
                        }
                    }
                }
            }
        }
        cout<<deposit<<endl;
    }
    return 0;
}