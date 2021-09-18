#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		int row, col;
		int i=0;
		for(int acc=0;;++i){
			if(acc>=n){
				row=i-1;
				col=acc-n;
				break;
			}
			acc+=i;
		}
		int son=1+col, mom=row-col;
		if(i&1==1){
			son=row-col;
			mom=1+col;
		}
		cout<<"TERM "<<n<<" IS "<<son<<"/"<<mom<<endl;
	}
	return 0;
}
