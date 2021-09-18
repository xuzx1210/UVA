#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		int digit=n>>1;
		for(int i=0;i<pow(10, digit);++i){
			int num=i*i;
			int arr[n];
			for(int j=0, tmp=num;j<n;++j){
				arr[j]=tmp%10;
				tmp/=10;
			}
			int a=0, b=0;
			for(int j=n-1;j>=digit;--j){
				a*=10;
				a+=arr[j];
			}
			for(int j=digit-1;j>=0;--j){
				b*=10;
				b+=arr[j];
			}
			if(a+b==i){
				cout<<setw(n)<<setfill('0')<<num<<endl;
			}
		}
	}
	return 0;
}
