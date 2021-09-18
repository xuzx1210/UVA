#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int t=0;t<n;++t){
        int s, d;
        cin>>s>>d;
        int x=s+d, y=s-d;
        if(x<0 || y<0 || x&1 || y&1){
            cout<<"impossible"<<endl;
        }else{
            x>>=1;
            y>>=1;
            cout<<max(x, y)<<' '<<min(x, y)<<endl;
        }
    }
    return 0;
}