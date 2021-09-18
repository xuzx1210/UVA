#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	double m=5;
	for(int i=0;i<10;i++){
		while(true){
			m++;
			double n=(sqrt(8*m*m+1)-1)/2;
			if(n==floor(n)){
				printf("%10.0f%10.0f\n", m, n);
				break;
			}
		}
	}
	return 0;
}
