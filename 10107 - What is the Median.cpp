#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> num;
    num.clear();
    int n;
    while(cin>>n){
        bool inserted=false;
        for(int i=0;i<num.size();++i){
            if(n<=num[i]){
                num.insert(num.begin()+i, n);
                inserted=true;
                break;
            }
        }
        if(!inserted){
            num.push_back(n);
        }
        if(num.size()&1){
            cout<<num[num.size()>>1]<<endl;
        }else{
            cout<<((num[num.size()>>1]+num[(num.size()>>1)-1])>>1)<<endl;
        }
    }
    return 0;
}