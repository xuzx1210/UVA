#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int testcase=0;testcase<t;++testcase){
        int people;
        cin>>people;
        int forward[people];
        bool checked[people];
        for(int i=0;i<people;++i){
            checked[i]=false;
        }
        for(int i=0;i<people;++i){
            int from, to;
            cin>>from>>to;
            forward[from-1]=to-1;
        }
        int Max=0, Maxi;
        for(int i=0;i<people;++i){
            if(checked[i]){
                continue;
            }
            bool visited[people];
            for(int i=0;i<people;++i){
                visited[i]=false;
            }
            int cur=i, forwards=0;
            while(!visited[cur]){
                visited[cur]=true;
                checked[cur]=true;
                ++forwards;
                cur=forward[cur];
            }
            if(forwards>Max){
                Max=forwards;
                Maxi=i;
            }
        }
        cout<<"Case "<<testcase+1<<": "<<Maxi+1<<endl;
    }
    return 0;
}