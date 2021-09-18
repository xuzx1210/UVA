#include<iostream>
#include<vector>
using namespace std;
void find_number(const int depth, const long long num, const int p, const long long mask, vector<long long> &nums){
    if(depth==p){
        if((num&mask)==0){
            nums.push_back(num);
        }
        return;
    }
    find_number(depth+1, num*10+1, p, mask, nums);
    find_number(depth+1, num*10+2, p, mask, nums);
}
int main(){
    int n;
    cin>>n;
    for(int t=0;t<n;++t){
        int p, q;
        cin>>p>>q;
        const long long mask=(1<<q)-1;
        vector<long long> nums;
        nums.clear();
        find_number(0, 0, p, mask, nums);
        cout<<"Case "<<t+1<<": ";
        if(nums.size()==0){
            cout<<"impossible"<<endl;
        }else if(nums.size()==1){
            cout<<nums[0]<<endl;
        }else{
            cout<<nums[0]<<' '<<nums[nums.size()-1]<<endl;
        }
    }
    return 0;
}