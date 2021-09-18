#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int l, r, c;
class point{
public:
    point(){
        i=0;
        j=0;
        k=0;
    }
    point(int a, int b, int c){
        i=a;
        j=b;
        k=c;
    }
    int i, j, k;
    bool out(){
        if(0<=i && i<l && 0<=j && j<r && 0<=k && k<c){
            return false;
        }
        return true;
    }
    void set(int a, int b, int c){
        i=a;
        j=b;
        k=c;
    }
    point operator+(point &right){
        point result(i+right.i, j+right.j, k+right.k);
        return result;
    }
    bool operator==(point right){
        if(i==right.i && j==right.j && k==right.k){
            return true;
        }
        return false;
    }
};
int main(){
    point direction[6];
    direction[0].set(-1, 0, 0);
    direction[1].set(1, 0, 0);
    direction[2].set(0, -1, 0);
    direction[3].set(0, 1, 0);
    direction[4].set(0, 0, -1);
    direction[5].set(0, 0, 1);
    while(true){
        cin>>l>>r>>c;
        if(l==0 && r==0 && c==0){
            break;
        }
        char dungeon[l][r][c];
        point s, e;
        for(int i=0;i<l;++i){
            for(int j=0;j<r;++j){
                for(int k=0;k<c;++k){
                    cin>>dungeon[i][j][k];
                    if(dungeon[i][j][k]=='S'){
                        s.set(i, j, k);
                    }else if(dungeon[i][j][k]=='E'){
                        e.set(i, j, k);
                    }
                }
            }
        }
        vector<point> visited;
        queue<pair<point, int>> next;
        next.push({s, 0});
        visited.push_back(s);
        bool escape=false;
        while(!next.empty()){
            point cur=next.front().first;
            const int t=next.front().second;
            if(cur==e){
                cout<<"Escaped in "<<t<<" minute(s)."<<endl;
                escape=true;
                break;
            }
            next.pop();
            for(int d=0;d<6;++d){
                point tmp=cur+direction[d];
                if(tmp.out()){
                    continue;
                }
                if(dungeon[tmp.i][tmp.j][tmp.k]=='#'){
                    continue;
                }
                if(find(visited.begin(), visited.end(), tmp)!=visited.end()){
                    continue;
                }
                next.push({tmp, t+1});
                visited.push_back(tmp);
            }
        }
        if(!escape){
            cout<<"Trapped!"<<endl;
        }
    }
    return 0;
}