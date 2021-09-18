#include<iostream>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
class Stone{
public:
    int x, y;
};
int main(){
    int t=0;
    while(true){
        int n;
        cin>>n;
        if(n==0){
            break;
        }
        ++t;
        Stone stone[n];
        for(int i=0;i<n;++i){
            cin>>stone[i].x>>stone[i].y;
        }
        double distance[n][n];
        for(int i=0;i<n;++i){
            distance[i][i]=2000.0;
        }
        for(int i=0;i<n-1;++i){
            for(int j=i+1;j<n;++j){
                int x=stone[i].x-stone[j].x, y=stone[i].y-stone[j].y;
                double d=sqrt(x*x+y*y);
                distance[i][j]=d;
                distance[j][i]=d;
            }
        }
        double frog_distance[n];
        for(int i=0;i<n;++i){
            frog_distance[i]=distance[0][i];
        }
        vector<int> unvisited;
        unvisited.clear();
        for(int i=1;i<n;++i){
            unvisited.push_back(i);
        }
        int cur=0;
        for(int jump=1;jump<n;++jump){
            double m=2000.0;
            vector<int>::iterator mit;
            for(vector<int>::iterator it=unvisited.begin();it!=unvisited.end();++it){
                if(frog_distance[*it]<m){
                    m=frog_distance[*it];
                    mit=it;
                }
            }
            cur=*mit;
            unvisited.erase(mit);
            for(int i=1;i<n;++i){
                frog_distance[i]=min(frog_distance[i], max(frog_distance[cur], distance[cur][i]));
            }
        }
        cout<<"Scenario #"<<t<<endl;
        cout<<"Frog Distance = "<<fixed<<setprecision(3)<<frog_distance[1]<<endl;
        cout<<endl;
    }
    return 0;
}