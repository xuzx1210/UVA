#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int t=0;t<n;++t){
        int farmer, sum=0;
        cin>>farmer;
        for(int f=0;f<farmer;++f){
            int area, animal, grade;
            cin>>area>>animal>>grade;
            sum+=area*grade;
        }
        cout<<sum<<endl;
    }
    return 0;
}