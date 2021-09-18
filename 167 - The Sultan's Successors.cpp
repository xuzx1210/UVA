#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
using namespace std;
void queen(int i, int *chess, vector<vector<int> > &chess_array){
	if(i==8){
		vector<int> tmp;
		for(int j=0;j<8;++j){
			tmp.push_back(chess[j]);
		}
		chess_array.push_back(tmp);
		return;
	}
	for(int j=0;j<8;++j){
		bool c=false;
		for(int k=0;k<i;++k){
			if(chess[k]==j || abs(j-chess[k])==(i-k)){
				c=true;
				break;
			}
		}
		if(!c){
			chess[i]=j;
			queen(i+1, chess, chess_array);
		}
	}
}
int main(){
	vector<vector<int> > chess_array;
	int chess[8];
	queen(0, chess, chess_array);
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		int table[8][8];
		for(int j=0;j<8;++j){
			for(int k=0;k<8;++k){
				cin>>table[j][k];
			}
		}
		int max=0;
		for(int j=0;j<chess_array.size();++j){
			int count=0;
			for(int k=0;k<8;++k){
				count+=table[k][chess_array[j][k]];
			}
			if(count>max){
				max=count;
			}
		}
		cout<<setw(5)<<max<<endl;
	}
	return 0;
}
