#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		if(n==0){
			break;
		}
		n--;
		for(int i=1;i<n;i++){
			int black=0;
			for(int j=1;j<=n;j++){
				black=(black+i)%j;
			}
			if(black==11){
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}
