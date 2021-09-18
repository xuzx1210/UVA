#include<iostream>
using namespace std;
int main(){
    int T;
    cin>>T;
    for(int t=0;t<T;++t){
        int n, m;
        cin>>n>>m;
        cout<<(n/3)*(m/3)<<endl;
    }
    return 0;
}