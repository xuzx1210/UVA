#include<iostream>
using namespace std;
int main(){
    while(true){
        int initial, first, second, third, degree=1080;
        cin>>initial>>first>>second>>third;
        if(initial==0 && first==0 && second==0 && third==0){
            break;
        }
        initial*=9;
        first*=9;
        second*=9;
        third*=9;
        degree+=initial-first;
        if(initial<first){
            degree+=360;
        }
        degree+=second-first;
        if(second<first){
            degree+=360;
        }
        degree+=second-third;
        if(second<third){
            degree+=360;
        }
        cout<<degree<<endl;
    }
    return 0;
}