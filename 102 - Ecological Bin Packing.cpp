#include<iostream>
#include<climits>
using namespace std;
int main(){
	int b[3], g[3], c[3];
	while(cin>>b[0]>>g[0]>>c[0]>>b[1]>>g[1]>>c[1]>>b[2]>>g[2]>>c[2]){
		int cost[6];
		cost[0]=g[0]+c[0]+b[1]+g[1]+b[2]+c[2];
		cost[1]=g[0]+c[0]+b[1]+c[1]+b[2]+g[2];
		cost[2]=b[0]+g[0]+g[1]+c[1]+b[2]+c[2];
		cost[3]=b[0]+g[0]+b[1]+c[1]+g[2]+c[2];
		cost[4]=b[0]+c[0]+g[1]+c[1]+b[2]+g[2];
		cost[5]=b[0]+c[0]+b[1]+g[1]+g[2]+c[2];
		int index, min=INT_MAX, i;
		for(i=0;i<6;i++){
			if(cost[i]<min){
				min=cost[i];
				index=i;
			}
		}
		switch(index){
			case 0:
				cout<<"BCG ";
				break;
			case 1:
				cout<<"BGC ";
				break;
			case 2:
				cout<<"CBG ";
				break;
			case 3:
				cout<<"CGB ";
				break;
			case 4:
				cout<<"GBC ";
				break;
			case 5:
				cout<<"GCB ";
				break;
		}
		cout<<cost[index]<<endl;
	}
	return 0;
} 
