#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	for(int game=1;;++game){
		int n;
		cin>>n;
		if(n==0){
			break;
		}
		cout<<"Game "<<game<<":"<<endl;
		int target[n];
		for(int i=0;i<n;++i){
			cin>>target[i];
		}
		int sorted[n];
		for(int i=0;i<n;++i){
			sorted[i]=target[i];
		}
		sort(sorted, sorted+n);
		int cur[n];
		while(true){
			for(int i=0;i<n;++i){
				cin>>cur[i];
			}
			if(cur[0]==0){
				break;
			}
			int a=0, b=0;
			for(int i=0;i<n;++i){
				if(target[i]==cur[i]){
					++a;
				}
			}
			sort(cur, cur+n);
			for(int i=0, j=0;i<n && j<n;){
				if(sorted[i]<cur[j]){
					++i;
				}else if(sorted[i]>cur[j]){
					++j;
				}else{
					++b;
					++i;
					++j;
				}
			}
			b-=a;
			cout<<"    ("<<a<<","<<b<<")"<<endl;
		}
	}
	return 0;
}
