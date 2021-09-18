#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#define N (100)
using namespace std;
void dfs(int *ring, const int n, const int depth, set<int> &used, vector<int> &prime){
    if(depth==n){
        if(find(prime.begin(), prime.end(), ring[n-1]+1)!=prime.end()){
            cout<<ring[0];
            for(int i=1;i<n;++i){
                cout<<" "<<ring[i];
            }
            cout<<endl;
        }
        return;
    }
    for(int i=1;i<=n;++i){
        if(find(prime.begin(), prime.end(), i+ring[depth-1])!=prime.end()){
            if(used.find(i)==used.end()){
                ring[depth]=i;
                used.insert(i);
                dfs(ring, n, depth+1, used, prime);
                used.erase(i);
            }
        }
    }
}
int main(){
    vector<int> prime;
    prime.push_back(2);
    prime.push_back(3);
    for(int i=6;i<N;i+=6){
        bool c=false;
        for(int j=0;j<prime.size();++j){
            if((i-1)%prime[j]==0){
                c=true;
                break;
            }
        }
        if(!c){
            prime.push_back(i-1);
        }
        c=false;
        for(int j=0;j<prime.size();++j){
            if((i+1)%prime[j]==0){
                c=true;
                break;
            }
        }
        if(!c){
            prime.push_back(i+1);
        }
    }
    int n, t=0;
    while(cin>>n){
        int ring[n];
        ring[0]=1;
        set<int> used;
        used.insert(1);
        if(t){
            cout<<endl;
        }
        ++t;
        cout<<"Case "<<t<<":"<<endl;
        dfs(ring, n, 1, used, prime);
    }
    return 0;
}