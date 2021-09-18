#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		char chess;
		int row, col;
		cin>>chess>>row>>col;
		switch(chess){
			case 'r':
				cout<<((row<col)?row:col)<<endl;
				break;
			case 'k':
				cout<<(row*col+1)/2<<endl;
				break;
			case 'Q':
				cout<<((row<col)?row:col)<<endl;
				break;
			case 'K':
				cout<<((row+1)/2)*((col+1)/2)<<endl;
				break;
		}
	}
	return 0;
}
