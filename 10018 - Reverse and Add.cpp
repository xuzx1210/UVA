#include<iostream>
typedef unsigned long long int ull;
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int t=0;t<n;++t){
        ull number;
        cin>>number;
        ull tmp=number, reverse=0;
        while(tmp){
            reverse=reverse*10+(tmp%10);
            tmp/=10;
        }
        int count=0;
        while(number!=reverse){
            number+=reverse;
            ++count;
            tmp=number;
            reverse=0;
            while(tmp){
                reverse=reverse*10+(tmp%10);
                tmp/=10;
            }
        }
        cout<<count<<' '<<number<<endl;
    }
    return 0;
}