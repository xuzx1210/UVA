#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include<cctype>
using namespace std;
int base_to_ten(vector<int> &num, int base){
    int result=0;
    for(int i=0;i<num.size();++i){
        result=result*base+num[i];
    }
    return result;
}
string ten_to_base(int num, int base){
    string result;
    while(num){
        int tmp=num%base;
        if(tmp<10){
            result.push_back(tmp+'0');
        }else{
            result.push_back(tmp+'A'-10);
        }
        num/=base;
    }
    reverse(result.begin(), result.end());
    return result;
}
int main(){
    string Num;
    int base1, base2;
    while(cin>>Num>>base1>>base2){
        vector<int> num;
        for(int i=0;i<Num.length();++i){
            if(isdigit(Num[i])){
                num.push_back(Num[i]-'0');
            }else{
                num.push_back(Num[i]-'A'+10);
            }
        }
        int ten=base_to_ten(num, base1);
        if(ten==0){
            cout<<"      0"<<endl;
            continue;
        }
        string result(ten_to_base(ten, base2));
        if(result.length()>7){
            cout<<"  ERROR"<<endl;
        }else{
            cout<<setw(7)<<result<<endl;
        }
    }
    return 0;
}