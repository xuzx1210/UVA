#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;
	cin>>n;
	cout<<"INTERSECTING LINES OUTPUT"<<endl;
	for(int i=0;i<n;++i){
		double x1, y1, x2, y2, x3, y3, x4, y4;
		cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
		if(x1==x2 || x3==x4){
			if(x1==x2 && x3==x4){
				if(x1==x3){
					cout<<"LINE"<<endl;
				}else{
					cout<<"NONE"<<endl;
				}
			}else if(x1==x2){
				double a, b;
				a=(y3-y4)/(x3-x4);
				b=y3-a*x3;
				printf("POINT %.2f %.2f\n", x1, a*x1+b);
			}else{
				double a, b;
				a=(y1-y2)/(x1-x2);
				b=y1-a*x1;
				printf("POINT %.2f %.2f\n", x3, a*x3+b);
			}
		}else{
			double a1, b1, a2, b2, x;
			a1=(y1-y2)/(x1-x2);
			b1=y1-a1*x1;
			a2=(y3-y4)/(x3-x4);
			b2=y3-a2*x3;
			if(a1==a2){
				if(b1==b2){
					cout<<"LINE"<<endl;
				}else{
					cout<<"NONE"<<endl;
				}
			}else{
				x=(b2-b1)/(a1-a2);
				printf("POINT %.2f %.2f\n", x, a1*x+b1);
			}
		}
	}
	cout<<"END OF OUTPUT"<<endl;
	return 0;
}
