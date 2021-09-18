#include<iostream>
using namespace std;
int main(){
	while(true){
		int n;
		cin>>n;
		if(n==0){
			break;
		}
		int seq[n];
		for(int i=0;i<n;++i){
			cin>>seq[i];
		}
		int k;
		cin>>k;
		for(int i=n-1;i>0;--i){
			for(int j=0;j<i;++j){
				seq[j]=seq[j+1]-seq[j];
			}
		}
		for(int i=0;i<k;++i){
			for(int j=1;j<n;++j){
				seq[j]+=seq[j-1];
			}
		}
		cout<<"Term "<<n+k<<" of the sequence is "<<seq[n-1]<<endl;
	}
	return 0;
}
