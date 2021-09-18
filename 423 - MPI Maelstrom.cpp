#include<iostream>
#include<string>
#include<sstream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int cost[n][n];
    for(int i=0;i<n;++i){
        cost[i][i]=0;
    }
    for(int i=1;i<n;++i){
        for(int j=0;j<i;++j){
            string time;
            cin>>time;
            if(time[0]=='x'){
                cost[i][j]=INT_MAX>>1;
                cost[j][i]=INT_MAX>>1;
            }else{
                stringstream ss(time);
                ss>>cost[i][j];
                cost[j][i]=cost[i][j];
            }
        }
    }
    int time[n];
    for(int i=0;i<n;++i){
        time[i]=cost[0][i];
    }
    int cur=0;
    vector<int> visited;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(time[j]>time[cur]+cost[j][cur]){
                time[j]=time[cur]+cost[j][cur];
            }
        }
        visited.push_back(cur);
        int min=INT_MAX, mini;
        for(int j=0;j<n;++j){
            if(count(visited.begin(), visited.end(), j)==0){
                if(time[j]<min){
                    min=time[j];
                    mini=j;
                }
            }
        }
        cur=mini;
    }
    int max=0;
    for(int i=0;i<n;++i){
        if(time[i]>max){
            max=time[i];
        }
    }
    cout<<max<<endl;
    return 0;
}