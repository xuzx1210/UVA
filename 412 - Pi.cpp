#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int gcd(int a, int b){
    while(b){
        int tmp=a%b;
        a=b;
        b=tmp;
    }
    return a;
}
int main(){
    int n;
    while(cin>>n){
        if(n==0){
            break;
        }
        int num[n];
        for(int i=0;i<n;++i){
            cin>>num[i];
        }
        int p=0;
        for(int i=0;i<n-1;++i){
            for(int j=i+1;j<n;++j){
                if(gcd(num[i], num[j])==1){
                    ++p;
                }
            }
        }
        if(p==0){
            cout<<"No estimate for this data set."<<endl;
        }else{
            printf("%.6f\n", sqrt((double)(3*n*(n-1))/(double)p));
        }
    }
    return 0;
}