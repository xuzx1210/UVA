#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    vector<string> nums;
    string tmp;
    cin>>tmp;
    int maxlen=0;
    for(;tmp!="0";cin>>tmp){
        if(tmp.length()>maxlen){
            maxlen=tmp.length();
        }
        reverse(tmp.begin(), tmp.end());
        nums.push_back(tmp);
    }
    int c=0;
    vector<int> result;
    for(int i=0;i<maxlen;++i){
        for(int j=0;j<nums.size();++j){
            if(i<nums[j].length()){
                c+=(nums[j][i]-'0');
            }
        }
        result.insert(result.begin(), c%10);
        c/=10;
    }
    if(c){
        cout<<c;
    }
    for(int i=0;i<result.size();++i){
        cout<<result[i];
    }
    cout<<endl;
    return 0;
}