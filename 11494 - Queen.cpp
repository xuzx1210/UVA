#include<iostream>
using namespace std;
int main(){
    while(true){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        if(x1+y1+x2+y2==0){
            break;
        }
        if(x1==x2 && y1==y2){
            cout<<'0'<<endl;
        }else if(x1==x2 || y1==y2 || x1+y1==x2+y2 || x1-y1==x2-y2){
            cout<<'1'<<endl;
        }else{
            cout<<'2'<<endl;
        }
    }
    return 0;
}