#include<iostream>
using namespace std;
bool g[5][5]={false};
int path[8];
void dfs(int now, int depth){
	if(depth==8){
		for(int i=0;i<8;++i){
			cout<<path[i]+1;
		}
		cout<<now+1<<endl;
		return;
	}
	path[depth]=now;
	for(int next=0;next<5;++next){
		if(g[now][next]){
			g[now][next]=false;
			g[next][now]=false;
			dfs(next, depth+1);
			g[now][next]=true;
			g[next][now]=true;
		}
	}
}
int main(){
	g[0][1]=true;
	g[0][2]=true;
	g[0][4]=true;
	g[1][0]=true;
	g[1][2]=true;
	g[1][4]=true;
	g[2][0]=true;
	g[2][1]=true;
	g[2][3]=true;
	g[2][4]=true;
	g[3][2]=true;
	g[3][4]=true;
	g[4][0]=true;
	g[4][1]=true;
	g[4][2]=true;
	g[4][3]=true;
	path[0]=0;
	dfs(0, 0);
	return 0;
}
