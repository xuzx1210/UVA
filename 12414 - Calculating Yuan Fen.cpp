#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    string name;
    while(cin>>name){
        bool found=false;
        for(int st=1;st<=10000;++st){
            vector<int> nums;
            nums.clear();
            for(int i=0;i<name.length();++i){
                nums.push_back(name[i]-'A'+st);
            }
            vector<int> digits;
            digits.clear();
            for(int i=nums.size()-1;i>=0;--i){
                while(nums[i]){
                    digits.push_back(nums[i]%10);
                    nums[i]/=10;
                }
            }
            reverse(digits.begin(), digits.end());
            while(digits.size()>=3){
                if(digits.size()==3){
                    if(digits[0]==1 && digits[1]==0 && digits[2]==0){
                        cout<<st<<endl;
                        found=true;
                    }
                    break;
                }
                for(int i=0;i<digits.size()-1;++i){
                    digits[i]=(digits[i]+digits[i+1])%10;
                }
                digits.pop_back();
            }
            if(found){
                break;
            }
        }
        if(!found){
            cout<<":("<<endl;
        }
    }
    return 0;
}