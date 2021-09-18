#include<iostream>
using namespace std;
int d(int n){
    int result=n;
    while(n){
        result+=(n%10);
        n/=10;
    }
    return result;
}
int main(){
    bool self[1000001];
    for(int i=1;i<=1000000;++i){
        self[i]=true;
    }
    for(int i=1;i<=1000000;++i){
        if(self[i]){
            int cur=d(i);
            while(cur<=1000000 && self[cur]){
                self[cur]=false;
                cur=d(cur);
            }
        }
    }
    for(int i=1;i<=1000000;++i){
        if(self[i]){
            cout<<i<<endl;
        }
    }
    return 0;
}