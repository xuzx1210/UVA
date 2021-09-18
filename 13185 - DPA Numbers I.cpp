#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int t=0;t<n;++t){
        int num;
        cin>>num;
        int s=floor(sqrt(num)), sum=1;
        for(int i=2;i*i<=num;++i){
            if((num%i)==0){
                sum+=(i+(num/i));
            }
        }
        if(s*s==num){
            sum-=s;
        }
        if(sum<num){
            cout<<"deficient"<<endl;
        }else if(sum>num){
            cout<<"abundant"<<endl;
        }else{
            cout<<"perfect"<<endl;
        }
    }
    return 0;
}