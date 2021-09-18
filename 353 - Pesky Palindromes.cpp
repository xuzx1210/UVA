#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
int main(){
	string line;
	while(cin>>line){
		vector<string> list;
		for(int i=0;i<line.length();++i){
			for(int j=i;j<line.length();++j){
				string word(line, i, j-i+1);
				stringstream ss;
				for(int k=word.length()-1;k>=0;--k){
					ss<<word[k];
				}
				string rword;
				ss>>rword;
				if(word==rword){
					bool c=false;
					for(int k=0;k<list.size();++k){
						if(word==list[k]){
							c=true;
							break;
						}
					}
					if(!c){
						list.push_back(word);
					}
				}
			}
		}
		cout<<"The string '"<<line<<"' contains "<<list.size()<<" palindromes."<<endl;
	}
	return 0;
}
