#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	string id;
	while(true){
		cin>>id;
		if(id=="#"){
			break;
		}
		if(next_permutation(id.begin(), id.end())){
			cout<<id<<endl;
		}else{
			cout<<"No Successor"<<endl;
		}
	}
	return 0;
}
