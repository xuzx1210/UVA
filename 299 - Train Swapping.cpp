#include<iostream>
using namespace std;
int main(){
	int N;
	cin>>N;
	for(int task=0;task<N;++task){
		int n;
		cin>>n;
		int train[n];
		for(int i=0;i<n;++i){
			cin>>train[i];
		}
		int swap=0;
		for(int i=0;i<n-1;++i){
			for(int j=0;j<n-1-i;++j){
				if(train[j]>train[j+1]){
					int tmp=train[j];
					train[j]=train[j+1];
					train[j+1]=tmp;
					++swap;
				}
			}
		}
		cout<<"Optimal train swapping takes "<<swap<<" swaps."<<endl;
	}
	return 0;
}
