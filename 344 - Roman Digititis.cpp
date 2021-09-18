#include<iostream>
using namespace std;
int i, v, x, l, c;
void count(int n){
	int a=n/10, b=n%10;
	switch(a){
		case 1: ++x; break;
		case 2: x+=2; break;
		case 3: x+=3; break;
		case 4: ++x; ++l; break;
		case 5: ++l; break;
		case 6: ++l; ++x; break;
		case 7: ++l; x+=2; break;
		case 8: ++l; x+=3; break;
		case 9: ++x; ++c; break;
		case 10: ++c; break;
		default: break;
	}
	switch(b){
		case 1: ++i; break;
		case 2: i+=2; break;
		case 3: i+=3; break;
		case 4: ++i; ++v; break;
		case 5: ++v; break;
		case 6: ++v; ++i; break;
		case 7: ++v; i+=2; break;
		case 8: ++v; i+=3; break;
		case 9: ++i; ++x; break;
		default: break;
	}
}
int main(){
	int n;
	while(cin>>n){
		if(n==0){
			break;
		}
		i=v=x=l=c=0;
		for(int j=1;j<=n;++j){
			count(j);
		}
		cout<<n<<": "<<i<<" i, "<<v<<" v, "<<x<<" x, "<<l<<" l, "<<c<<" c"<<endl;
	}
	return 0;
}
