#include<iostream>
#define N (200)
using namespace std;
int p[N];
void prime(){
	int max=2;
	for(int i=1;;++i){
		int num=6*i-1;
		bool c=false;
		for(int j=0;j<max;++j){
			if(num%p[j]==0){
				c=true;
				break;
			}
		}
		if(!c){
			p[max++]=num;
		}
		if(max==N){
			break;
		}
		num=6*i+1;
		c=false;
		for(int j=0;j<max;++j){
			if(num%p[j]==0){
				c=true;
				break;
			}
		}
		if(!c){
			p[max++]=num;
		}
		if(max==N){
			break;
		}
	}
}
int divisor(int n){
	int d[N];
	for(int i=0;i<N;++i){
		d[i]=1;
	}
	for(int i=0;i<N;++i){
		while(n%p[i]==0){
			n/=p[i];
			++d[i];
		}
	}
	int result=1;
	for(int i=0;i<N;++i){
		result*=d[i];
	}
	return result;
}
int main(){
	p[0]=2;
	p[1]=3;
	prime();
	int n;
	cin>>n;
	for(int task=0;task<n;++task){
		int L, R;
		cin>>L>>R;
		int max=0;
		int maxi, maxd;
		for(int i=L;i<=R;++i){
			int d=divisor(i);
			if(d>max){
				max=d;
				maxi=i;
				maxd=d;
			}
		}
		cout<<"Between "<<L<<" and "<<R<<", "<<maxi<<" has a maximum of "<<maxd<<" divisors."<<endl;
	}
	return 0;
}
