#include<iostream>
#include<algorithm>
typedef unsigned long long int ulli;
using namespace std;
ulli Ackermann(ulli n){
	if(n==1){
		return 3;
	}
	ulli count=0;
	while(n!=1){
		if(n&1){
			n=3*n+1;
		}else{
			n>>=1;
		}
		++count;
	}
	return count;
}
int main(){
	ulli L, H;
	while(cin>>L>>H){
		if(L>H){
			swap(L, H);
		}
		if(H==0){
			break;
		}
		ulli max=0, maxi=0;
		for(ulli V=L;V<=H;++V){
			ulli S=Ackermann(V);
			if(S>max){
				max=S;
				maxi=V;
			}
		}
		cout<<"Between "<<L<<" and "<<H<<", "<<maxi<<" generates the longest sequence of "<<max<<" values."<<endl;
	}
	return 0;
}
