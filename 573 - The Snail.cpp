#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    while(true){
        double h, u, d, f;
        cin>>h>>u>>d>>f;
        if(h==0){
            break;
        }
        double height=0.0, fatigue=u*f/100.0;
        for(int day=1;;++day){
            height+=u;
            if(height>h){
                cout<<"success on day "<<day<<endl;
                break;
            }
            height-=d;
            if(height<0.0){
                cout<<"failure on day "<<day<<endl;
                break;
            }
            u=max(0.0, u-fatigue);
        }
    }
    return 0;
}