#include<iostream>
using namespace std;
void wave(const int a){
    for(int i=1;i<=a;++i){
        for(int j=0;j<i;++j){
            cout<<i;
        }
        cout<<endl;
    }
    for(int i=a-1;i>=1;--i){
        for(int j=0;j<i;++j){
            cout<<i;
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    for(int t=0;t<n;++t){
        int a, f;
        cin>>a>>f;
        for(int i=0;i<f;++i){
            if(t || i){
                cout<<endl;
            }
            wave(a);
        }
    }
    return 0;
}