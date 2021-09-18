#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int t=0;t<n;++t){
        int r;
        cin>>r;
        int s[r];
        for(int i=0;i<r;++i){
            cin>>s[i];
        }
        sort(s, s+r);
        int vito=s[r>>1], result=0;
        for(int i=0;i<r;++i){
            result+=abs(vito-s[i]);
        }
        cout<<result<<endl;
    }
    return 0;
}