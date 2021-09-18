#include<iostream>
#include<string>
using namespace std;
int X, Y, x, y;
char dir;
bool sign[50][50]={false};
void left(){
	switch(dir){
		case 'N':
			dir='W';
			break;
		case 'S':
			dir='E';
			break;
		case 'W':
			dir='S';
			break;
		case 'E':
			dir='N';
			break;
	}
}
void right(){
	switch(dir){
		case 'N':
			dir='E';
			break;
		case 'S':
			dir='W';
			break;
		case 'W':
			dir='N';
			break;
		case 'E':
			dir='S';
			break;
	}
}
void forward(bool &fall){
	if((dir=='N' && y==Y) || (dir=='S' && y==0) || (dir=='W' && x==0) || (dir=='E' && x==X)){
		if(sign[x][y]){
			return;
		}
		fall=true;
		sign[x][y]=true;
		return;
	}
	switch(dir){
		case 'N':
			y++;
			break;
		case 'S':
			y--;
			break;
		case 'W':
			x--;
			break;
		case 'E':
			x++;
			break;
	}
}
int main(){
	cin>>X>>Y;
	while(cin>>x>>y>>dir){
		string cmd;
		cin>>cmd;
		bool fall=false;
		for(int i=0;i<cmd.length();i++){
			if(cmd[i]=='L'){
				left();
			}else if(cmd[i]=='R'){
				right();
			}else{
				forward(fall);
				if(fall){
					break;
				}
			}
		}
		cout<<x<<" "<<y<<" "<<dir;
		if(fall){
			cout<<" LOST";
		}
		cout<<endl;
	}
	return 0;
}
