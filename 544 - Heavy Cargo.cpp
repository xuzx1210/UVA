#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int index(string a, string *city, int n){
    for(int i=0;i<n;++i){
        if(a==city[i]){
            return i;
        }
    }
}
int main(){
    for(int scenario=1;;++scenario){
        int n, r;
        cin>>n>>r;
        if(n==0 && r==0){
            break;
        }
        string city[n];
        int connection[n][n];
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                connection[i][j]=0;
            }
        }
        vector<string> recorded;
        recorded.clear();
        int c=0;
        for(int i=0;i<r;++i){
            string a, b;
            int load;
            cin>>a>>b>>load;
            if(find(recorded.begin(), recorded.end(), a)==recorded.end()){
                recorded.push_back(a);
                city[c++]=a;
            }
            if(find(recorded.begin(), recorded.end(), b)==recorded.end()){
                recorded.push_back(b);
                city[c++]=b;
            }
            int ai=index(a, city, n), bi=index(b, city, n);
            connection[ai][bi]=load;
            connection[bi][ai]=load;
        }
        string s, e;
        cin>>s>>e;
        int start=index(s, city, n), end=index(e, city, n);
        int cur=start;
        vector<int> visited;
        visited.clear();
        visited.push_back(start);
        int load[n];
        for(int i=0;i<n;++i){
            load[i]=connection[start][i];
        }
        for(int time=1;time<n;++time){
            int M=0;
            for(int i=0;i<n;++i){
                if(find(visited.begin(), visited.end(), i)==visited.end()){
                    if(load[i]>M){
                        M=load[i];
                        cur=i;
                    }
                }
            }
            visited.push_back(cur);
            for(int i=0;i<n;++i){
                load[i]=max(load[i], min(load[cur], connection[cur][i]));
            }
        }
        cout<<"Scenario #"<<scenario<<endl;
        cout<<load[end]<<" tons"<<endl;
        cout<<endl;
    }
    return 0;
}