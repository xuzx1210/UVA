#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;
int main(){
	string line;
	while(getline(cin, line)){
		stringstream ss;
		ss<<line;
		string word;
		vector<int> w;
		while(ss>>word){
			int tmp=0;
			for(int i=0;i<word.length();i++){
				tmp=tmp<<5;
				tmp+=(word[i]-'a'+1);
			}
			w.push_back(tmp);
		}
		int n=w.size();
		for(int c=1;;c++){
			bool collision=false;
			for(int i=0;i<n-1;i++){
				for(int j=i+1;j<n;j++){
					if(((c/w[i])%n)==((c/w[j])%n)){
						collision=true;
						break;
					}
				}
				if(collision){
					break;
				}
			}
			if(collision){
				continue;
			}
			cout<<line<<endl<<c<<endl<<endl;
			break;
		}
	}
	return 0;
}
