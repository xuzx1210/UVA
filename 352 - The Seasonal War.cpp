#include<iostream>
using namespace std;
void dfs(bool *map, int n, int i, int j){
	map[i*n+j]=false;
	if(i>0 && j>0){
		if(map[(i-1)*n+j-1]){
			dfs(map, n, i-1, j-1);
		}
	}
	if(i>0){
		if(map[(i-1)*n+j]){
			dfs(map, n, i-1, j);
		}
	}
	if(i>0 && j<n-1){
		if(map[(i-1)*n+j+1]){
			dfs(map, n, i-1, j+1);
		}
	}
	if(j>0){
		if(map[i*n+j-1]){
			dfs(map, n, i, j-1);
		}
	}
	if(j<n-1){
		if(map[i*n+j+1]){
			dfs(map, n, i, j+1);
		}
	}
	if(i<n-1 && j>0){
		if(map[(i+1)*n+j-1]){
			dfs(map, n, i+1, j-1);
		}
	}
	if(i<n-1){
		if(map[(i+1)*n+j]){
			dfs(map, n, i+1, j);
		}
	}
	if(i<n-1 && j<n-1){
		if(map[(i+1)*n+j+1]){
			dfs(map, n, i+1, j+1);
		}
	}
}
int main(){
	int n, image=1;
	while(cin>>n){
		bool map[n*n];
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				char tmp;
				cin>>tmp;
				map[i*n+j]=tmp-'0';
			}
		}
		int eagle=0;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(map[i*n+j]){
					dfs(map, n, i, j);
					++eagle;
				}
			}
		}
		cout<<"Image number "<<image<<" contains "<<eagle<<" war eagles."<<endl;
		++image;
	}
	return 0;
}
