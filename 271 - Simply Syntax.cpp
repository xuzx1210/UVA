#include<iostream>
#include<string>
using namespace std;
bool check(string &sentence){
	int num=0;
	for(int i=sentence.size()-1;i>=0;--i){
		char c=sentence[i];
		if('p'<=c && c<='z'){
			++num;
		}else if(c=='N'){
			if(num==0){
				return false;
			}
		}else if(c=='C' || c=='D' || c=='E' || c=='I'){
			if(num<2){
				return false;
			}
			--num;
		}else{
			return false;
		}
	}
	return (num==1);
}
int main(){
	string sentence;
	while(cin>>sentence){
		cout<<(check(sentence)?"YES":"NO")<<endl;
	}
	return 0;
}
