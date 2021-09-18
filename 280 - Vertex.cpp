#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
void dfs(int n, int cur, vector<int>& found, bool *v){
	for(int i=0;i<n;++i){
		if(v[cur*n+i]){
			bool c=false;
			for(int j=0;j<found.size();++j){
				if(i==found[j]){
					c=true;
					break;
				}
			}
			if(!c){
				found.push_back(i);
				dfs(n, i, found, v);
			}
		}
	}
	return;
}
int main(){
	int n;
	while(true){
		cin>>n;
		if(n==0){
			break;
		}
		bool v[n*n];
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				v[i*n+j]=false;
			}
		}
		string vertex;
		getline(cin, vertex);
		while(true){
			getline(cin, vertex);
			if(vertex=="0"){
				break;
			}
			stringstream ss;
			ss<<vertex;
			int src, dst;
			ss>>src;
			while(true){
				ss>>dst;
				if(dst==0){
					break;
				}
				v[(src-1)*n+dst-1]=true;
			}
		}
		int m;
		cin>>m;
		for(int i=0;i<m;++i){
			int src;
			cin>>src;
			vector<int> found;
			dfs(n, src-1, found, v);
			bool inac[n];
			for(int j=0;j<n;++j){
				inac[j]=true;
			}
			for(int j=0;j<found.size();++j){
				inac[found[j]]=false;
			}
			cout<<n-found.size();
			for(int j=0;j<n;++j){
				if(inac[j]){
					cout<<" "<<j+1;
				}
			}
			cout<<endl;
		}
	}
	return 0;
}
