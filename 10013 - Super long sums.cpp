#include<iostream>
#include<stack>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int t=0;t<n;++t){
        if(t){
            cout<<endl;
        }
        int m;
        cin>>m;
        stack<pair<int, int>> nums;
        while(!nums.empty()){
            nums.pop();
        }
        for(int i=0;i<m;++i){
            int a, b;
            cin>>a>>b;
            nums.push({a, b});
        }
        stack<int> sum;
        while(!sum.empty()){
            sum.pop();
        }
        int carry=0;
        while(!nums.empty() || carry!=0){
            int s=nums.top().first+nums.top().second+carry;
            nums.pop();
            sum.push((s)%10);
            carry=(s)/10;
        }
        while(!sum.empty()){
            cout<<sum.top();
            sum.pop();
        }
        cout<<endl;
    }
    return 0;
}