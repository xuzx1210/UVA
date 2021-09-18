#include<iostream>
#include<vector>
using namespace std;
int main(){
	for(int Case=1;;++Case){
		int Z, I, M, L;
		cin>>Z>>I>>M>>L;
		if(Z==0){
			break;
		}
		int len;
		vector<int> num;
		bool loop=false;
		for(int i=0;;++i){
			for(int j=0;j<num.size();++j){
				if(num[j]==L){
					len=i-j;
					loop=true;
					break;
				}
			}
			if(loop){
				break;
			}
			num.push_back(L);
			L=(Z*L+I)%M;
		}
		cout<<"Case "<<Case<<": "<<len<<endl;
	}
	return 0;
}
