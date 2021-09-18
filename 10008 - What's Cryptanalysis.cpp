#include<iostream>
#include<string>
#include<cctype>
using namespace std;
typedef struct{
	char c;
	int count;
}Alpha;
int main(){
	int n;
	cin>>n;
	Alpha alpha[26];
	for(int i=0;i<26;i++){
		alpha[i].c=i+'A';
		alpha[i].count=0;
	}
	string firstline;
	getline(cin, firstline);
	for(int i=0;i<n;i++){
		string line;
		getline(cin, line);
		for(int j=0;j<line.length();j++){
			if(isalpha(line[j])){
				alpha[toupper(line[j])-'A'].count++;
			}
		}
	}
	for(int i=0;i<25;i++){
		for(int j=i+1;j<26;j++){
			if(alpha[i].count<alpha[j].count){
				Alpha tmp=alpha[i];
				alpha[i]=alpha[j];
				alpha[j]=tmp;
			}else if(alpha[i].count==alpha[j].count){
				if(alpha[i].c>alpha[j].c){
					Alpha tmp=alpha[i];
					alpha[i]=alpha[j];
					alpha[j]=tmp;
				}
			}
		}
	}
	for(int i=0;i<26;i++){
		if(alpha[i].count==0){
			break;
		}
		cout<<alpha[i].c<<" "<<alpha[i].count<<endl;
	}
	return 0;
}
