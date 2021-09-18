#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    while(true){
        int hour, minute;
        char colon;
        cin>>hour>>colon>>minute;
        if(hour==0 && minute==0){
            break;
        }
        double h=hour*30.0+minute*0.5, m=minute*6.0;
        while(h>360.0){
            h-=360.0;
        }
        while(m>360.0){
            m-=360.0;
        }
        double result=max(h, m)-min(h, m);
        printf("%.3f\n", min(result, 360.0-result));
    }
    return 0;
}