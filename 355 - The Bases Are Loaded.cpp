#include<iostream>
#include<vector>
#include<cctype>
#include<sstream>
#include<string>
#include<algorithm>
typedef unsigned long long int ulli;
using namespace std;
bool check(ulli &base, vector<ulli> &num){
	for(int i=0;i<num.size();++i){
		if(num[i]>=base || num[i]<0){
			return false;
		}
	}
	return true;
}
ulli base_to_ten(ulli &base, vector<ulli> &num){
	ulli result=0;
	for(int i=0;i<num.size();++i){
		result*=base;
		result+=num[i];
	}
	return result;
}
string ten_to_base(ulli &base, ulli num){
	stringstream ss;
	while(num){
		int digit=num%base;
		if(digit>9){
			ss<<(char)('A'+digit-10);
		}else{
			ss<<digit;
		}
		num/=base;
	}
	string result;
	ss>>result;
	reverse(result.begin(), result.end());
	return result;
}
int main(){
	ulli base1, base2;
	string Num;
	while(cin>>base1>>base2>>Num){
		vector<ulli> num;
		for(int i=0;i<Num.length();++i){
			if(isdigit(Num[i])){
				num.push_back(Num[i]-'0');
			}else{
				num.push_back(Num[i]-'A'+10);
			}
		}
		if(!check(base1, num)){
			cout<<Num<<" is an illegal base "<<base1<<" number"<<endl;
		}else{
			ulli ten=base_to_ten(base1, num);
			if(ten==0){
				cout<<Num<<" base "<<base1<<" = "<<"0 base "<<base2<<endl;
			}else{
				cout<<Num<<" base "<<base1<<" = "<<ten_to_base(base2, ten)<<" base "<<base2<<endl;
			}
		}
	}
	return 0;
}
