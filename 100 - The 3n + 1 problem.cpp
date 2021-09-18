#include<iostream>
using namespace std;
int count(int n){
	int result=1;
	while(n!=1){
		n=((n&1)?(3*n+1):(n>>1));
		++result;
	}
	return result;
}
int main(){
	int a, b;
	while(cin>>a>>b){
		cout<<a<<' '<<b<<' ';
		if(a>b){
			swap(a, b);
		}
		int M=0;
		for(int i=a;i<=b;++i){
			M=max(M, count(i));
		}
		cout<<M<<endl;
	}
	return 0;
} 
