#include<iostream>
using namespace std;
int main(){
	int n, m;
	unsigned long long int C[101][101];
	for(int i=0;i<=100;++i){
		C[i][0]=1;
		C[i][i]=1;
	}
	for(int i=2;i<=100;++i){
		for(int j=1;j<i;++j){
			C[i][j]=C[i-1][j-1]+C[i-1][j];
		}
	}
	while(true){
		cin>>n>>m;
		if(n==0){
			break;
		}
		cout<<n<<" things taken "<<m<<" at a time is "<<C[n][m]<<" exactly."<<endl;
	}
	return 0;
}
