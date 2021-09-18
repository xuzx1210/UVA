#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int t=0;t<n;++t){
        int e, f, c;
        cin>>e>>f>>c;
        int bottle=e+f, soda=0;
        while(bottle>=c){
            soda+=(bottle/c);
            bottle=(bottle/c)+(bottle%c);
        }
        cout<<soda<<endl;
    }
    return 0;
}