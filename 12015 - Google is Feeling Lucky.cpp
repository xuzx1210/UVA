#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int t=0;t<n;++t){
        pair<string, int> page[10];
        int m=0;
        for(int i=0;i<10;++i){
            cin>>page[i].first>>page[i].second;
            m=max(m, page[i].second);
        }
        cout<<"Case #"<<t+1<<':'<<endl;
        for(int i=0;i<10;++i){
            if(page[i].second==m){
                cout<<page[i].first<<endl;
            }
        }
    }
    return 0;
}