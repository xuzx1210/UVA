#include<iostream>
#include<climits>
using namespace std;
void print(int *cut, int i, int j, int n){
	if(i==j){
		cout<<"A"<<i+1;
	}else{
		cout<<"(";
		print(cut, i, cut[i*n+j], n);
		cout<<" x ";
		print(cut, cut[i*n+j]+1, j, n);
		cout<<")";
	}
}
int main(){
	for(int Case=1;;++Case){
		int n;
		cin>>n;
		if(n==0){
			break;
		}
		int mat[n+1];
		cin>>mat[0]>>mat[1];
		for(int i=2;i<=n;++i){
			int tmp;
			cin>>tmp>>mat[i];
		}
		int cost[n][n], cut[n*n];
		for(int i=0;i<n;++i){
			cost[i][i]=0;
		}
		for(int l=2;l<=n;++l){
			for(int i=0;i<=n-l;++i){
				int j=i+l-1;
				cost[i][j]=INT_MAX;
				for(int k=i;k<j;++k){
					int tmp=cost[i][k]+cost[k+1][j]+mat[i]*mat[k+1]*mat[j+1];
					if(tmp<cost[i][j]){
						cost[i][j]=tmp;
						cut[i*n+j]=k;
					}
				}
			}
		}
		cout<<"Case "<<Case<<": ";
		print(cut, 0, n-1, n);
		cout<<endl;
	}
	return 0;
}
