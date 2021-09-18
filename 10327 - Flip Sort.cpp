#include<iostream>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        int num[n];
        for(int i=0;i<n;++i){
            cin>>num[i];
        }
        int flip=0;
        for(int i=n-1;i>=0;--i){
            for(int j=0;j<i;++j){
                if(num[j]>num[j+1]){
                    swap(num[j], num[j+1]);
                    ++flip;
                }
            }
        }
        cout<<"Minimum exchange operations : "<<flip<<endl;
    }
    return 0;
}