#include<iostream>
#include<string>
using namespace std;
int main(){
	string line;
	bool quote=false;
	while(getline(cin, line)){
		for(int i=0;i<line.length();++i){
			if(line[i]=='"'){
				if(!quote){
					cout<<"``";
					quote=true;
				}else{
					cout<<"''";
					quote=false;
				}
			}else{
				cout<<line[i];
			}
		}
		cout<<endl;
	}
	return 0;
}
