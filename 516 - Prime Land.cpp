#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#define N (32767)
using namespace std;
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
    string line;
    while(getline(cin, line)){
        if(line[0]=='0'){
            break;
        }
        stringstream ss(line);
        int base, exponential, n=1;
        while(ss>>base>>exponential){
            for(int i=0;i<exponential;++i){
                n*=base;
            }
        }
        --n;
        vector<pair<int, int>> result;
        for(int i=prime.size()-1;i>=0;--i){
            exponential=0;
            while(n%prime[i]==0){
                ++exponential;
                n/=prime[i];
            }
            if(exponential){
                result.push_back({prime[i], exponential});
            }
            if(n==1){
                break;
            }
        }
        for(int i=0;i<result.size();++i){
            if(i){
                cout<<" ";
            }
            cout<<result[i].first<<" "<<result[i].second;
        }
        cout<<endl;
    }
    return 0;
}