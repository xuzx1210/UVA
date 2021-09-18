#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cctype>
using namespace std;
typedef struct aaa{
	string word;
	string sorted;
	bool use;//initial false
}Dict;
bool compare(string a, string b){
	for(int i=0;i<a.length() && i<b.length();i++){
		if(a[i]<b[i]){
			return false;
		}else if(a[i]>b[i]){
			return true;
		}else{
			continue;
		}
	}
	//a[0]-a[i]==b[0]-b[i]
	if(a.length()>b.length()){
		return true;
	}else{
		return false;
	}
}
int main(){
	string input;
	vector<Dict> dict;
	while(cin>>input){
		if(input=="#"){
			break;
		}
		string tmp(input);
		for(int i=0;i<tmp.length();i++){
			tmp[i]=tolower(tmp[i]);
		}
		sort(tmp.begin(), tmp.end());
		bool c=false;
		for(int i=0;i<dict.size();i++){
			if(tmp==dict[i].sorted){
				dict[i].use=true;
				c=true;
				break;
			}
		}
		if(!c){
			Dict a;
			a.word=input;
			a.sorted=tmp;
			a.use=false;
			dict.push_back(a);
		}
	}
	for(int i=0;i<dict.size()-1;i++){
		for(int j=i+1;j<dict.size();j++){
			if(compare(dict[i].word, dict[j].word)){
				Dict tmp=dict[i];
				dict[i]=dict[j];
				dict[j]=tmp;
			}
		}
	}
	for(int i=0;i<dict.size();i++){
		if(!dict[i].use){
			cout<<dict[i].word<<endl;
		}
	}
	return 0;
}
