#include<iostream>
using namespace std;
bool sorted(int *arr, int n){
	for(int i=0;i<n-1;++i){
		if(arr[i]>arr[i+1]){
			return false;
		}
	}
	return true;
}
void dfs(int *arr, int n, int &map){
	if(sorted(arr, n)){
		++map;
		return;
	}
	for(int i=0;i<n-1;++i){
		if(arr[i]>arr[i+1]){
			int tmp=arr[i];
			arr[i]=arr[i+1];
			arr[i+1]=tmp;
			dfs(arr, n, map);
			tmp=arr[i];
			arr[i]=arr[i+1];
			arr[i+1]=tmp;
		}
	}
}
int main(){
	for(int set=1;;++set){
		int n;
		cin>>n;
		if(n==0){
			break;
		}
		int arr[n];
		for(int i=0;i<n;++i){
			cin>>arr[i];
		}
		if(sorted(arr, n)){
			cout<<"There are 0 swap maps for input data set "<<set<<"."<<endl;
		}else{
			int map=0;
			dfs(arr, n, map);
			cout<<"There are "<<map<<" swap maps for input data set "<<set<<"."<<endl;
		}
	}
	return 0;
}
