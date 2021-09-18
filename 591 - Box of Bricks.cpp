#include<iostream>
using namespace std;
int main(){
    int set=0;
    while(true){
        int n;
        cin>>n;
        if(n==0){
            break;
        }
        ++set;
        int height[n], sum=0;
        for(int i=0;i<n;++i){
            cin>>height[i];
            sum+=height[i];
        }
        sum/=n;
        int moves=0;
        for(int i=0;i<n;++i){
            moves+=(height[i]>sum?height[i]-sum:0);
        }
        cout<<"Set #"<<set<<endl;
        cout<<"The minimum number of moves is "<<moves<<'.'<<endl;
        cout<<endl;
    }
    return 0;
}