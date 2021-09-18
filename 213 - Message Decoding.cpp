#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<sstream>
#include<iomanip>
using namespace std;
typedef struct{
	string index;
	char c;
}Node;
void dectobin(int n, int len, string& result){
	vector<int> num;
	int mask=1;
	for(int i=0;i<len;++i){
		if(n&mask){
			num.push_back(1);
		}else{
			num.push_back(0);
		}
		mask<<=1;
	}
	stringstream ss;
	for(int i=num.size()-1;i>=0;--i){
		ss<<num[i];
	}
	ss>>result;
	return;
}
int bintodec(string& bin){
	int result=0;
	for(int i=0;i<bin.length();++i){
		result<<=1;
		result+=(bin[i]-'0');
	}
	return result;
}
int main(){
	string input;
	bool last=false;
	while(getline(cin, input)){//one test case
		if(last){
			getline(cin, input);
		}
		last=true;
		vector<Node> list;
		int len=1;
		string index("0");
		for(int i=0;i<input.length();++i){
			Node tmp;
			tmp.index=index;
			tmp.c=input[i];
			list.push_back(tmp);
			int t=bintodec(index)+1;
			if(t==(1<<len)-1){
				++len;
				stringstream ss;
				for(int j=0;j<len;++j){
					ss<<'0';
				}
				ss>>index;
			}else{
				dectobin(t, len, index);
			}
		}
		vector<char> output;
		while(true){//one length
			int codelen=0;
			for(int i=0;i<3;++i){
				char t;
				cin>>t;
				codelen<<=1;
				if(t-'0'==1){
					codelen|=1;
				}
			}
			if(codelen==0){//length==0
				break;
			}
			while(true){//one code
				stringstream ss;
				for(int i=0;i<codelen;++i){
					char t;
					cin>>t;
					ss<<t;
				}
				string code;
				ss>>code;
				if(bintodec(code)==(1<<code.length())-1){//not code
					break;
				}
				for(int i=0;i<list.size();++i){
					if(list[i].index==code){
						output.push_back(list[i].c);
						break;
					}
				}
			}
		}
		for(int i=0;i<output.size();++i){
			cout<<output[i];
		}
		int pk=cin.peek();
		if(pk!=EOF){
			cout<<endl;
		}
	}
	return 0;
}
