#include<cstdio>
#include<iostream>
typedef unsigned long long int ulli;
using namespace std;
ulli mod(ulli b, ulli p, ulli m){
	if(p==0){
		return 1;
	}
	if(p==1){
		return b;
	}
	ulli half=mod(b, p>>1, m);
	if(p&1){
		return (half*half*b)%m;
	}else{
		return (half*half)%m;
	}
}
int main(){
	ulli b, p, m;
	while(scanf("%lld%lld%lld", &b, &p, &m)==3){
		cout<<mod(b%m, p, m)<<endl;
	}
	return 0;
}
