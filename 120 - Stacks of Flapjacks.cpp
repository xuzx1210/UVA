#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
int main(){
	string line;
	while(getline(cin, line)){
		cout<<line<<endl;
		stringstream linestream(line);
		vector<int> pancake, sorted;
		int diameter;
		while(linestream>>diameter){
			pancake.push_back(diameter);
			sorted.push_back(diameter);
		}
		sort(sorted.begin(), sorted.end());
		vector<int> step;
		for(int i=pancake.size()-1;i>=0;i--){
			if(pancake[i]==sorted[i]){
				continue;
			}
			for(int j=0;j<i;j++){
				if(pancake[j]==sorted[i]){
					if(j!=0){
						reverse(pancake.begin(), pancake.begin()+j+1);
						step.push_back(pancake.size()-j);
					}
					reverse(pancake.begin(), pancake.begin()+i+1);
					step.push_back(pancake.size()-i);
					break;
				}
			}
		}
		for(int i=0;i<step.size();i++){
			cout<<step[i]<<" ";
		}
		cout<<"0"<<endl;
	}
	return 0;
}
