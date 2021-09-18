#include<iostream>
using namespace std;
int count1(int n){
	int count=0;
	for(int i=0;i<32;++i){
		if(n&1){
			++count;
		}
		n>>=1;
	}
	return count;
}
int hextodec(int n){
	int dec[32];
	for(int i=0;i<32;++i){
		dec[i]=n%10;
		n/=10;
	}
	int hex=0;
	for(int i=31;i>=0;--i){
		hex*=16;
		hex+=dec[i];
	}
	return hex;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		int m;
		cin>>m;
		int b1=count1(m);
		int b2=count1(hextodec(m));
		cout<<b1<<" "<<b2<<endl;
	}
	return 0;
}
