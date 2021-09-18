#include<iostream>
#include<cmath>
using namespace std;
int main(){
	double n, p;
	while(cin>>n>>p){
		double a=pow(p, 1.0/n);
		int b=a;
		if(a-b<0.5){
			cout<<b<<endl;
		}else{
			cout<<b+1<<endl;
		}
	}
	return 0;
}
