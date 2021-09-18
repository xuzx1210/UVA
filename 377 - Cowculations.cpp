#include<iostream>
#include<string>
using namespace std;
int string_to_int(string &Num){
	int num=0;
	for(int i=0;i<Num.length();++i){
		num<<=2;
		switch(Num[i]){
			case 'U': ++num; break;
			case 'C': num+=2; break;
			case 'D': num+=3; break;
			default: break;
		}
	}
	return num;
}
void action(string &cmd, int &num1, int &num2){
	if(cmd=="A"){
		num2+=num1;
	}else if(cmd=="R"){
		num2>>=2;
	}else if(cmd=="L"){
		num2<<=2;
	}
}
int main(){
	int n;
	cin>>n;
	string line;
	getline(cin, line);
	cout<<"COWCULATIONS OUTPUT"<<endl;
	for(int i=0;i<n;++i){
		string Num1, Num2;
		getline(cin, Num1);
		getline(cin, Num2);
		int num1=string_to_int(Num1), num2=string_to_int(Num2);
		for(int j=0;j<3;++j){
			string cmd;
			getline(cin, cmd);
			action(cmd, num1, num2);
		}
		string Result;
		getline(cin, Result);
		int result=string_to_int(Result);
		if(result==num2){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	cout<<"END OF OUTPUT"<<endl;
	return 0;
}
