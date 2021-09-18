#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main(){
	string line;
	while(getline(cin, line)){
		bool last=false;
		int count=0;
		for(int i=0;i<line.length();++i){
			if(isalpha(line[i])){
				if(!last){
					++count;
					last=true;
				}
			}else{
				if(last){
					last=false;
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
