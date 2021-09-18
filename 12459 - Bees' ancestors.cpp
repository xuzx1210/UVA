#include<iostream>
#include<vector>
using namespace std;
typedef unsigned long long int ull;
int main(){
    vector<ull> fib;
    fib.clear();
    fib.push_back(1);
    fib.push_back(1);
    for(int i=2;i<=80;++i){
        fib.push_back(fib[fib.size()-2]+fib[fib.size()-1]);
    }
    while(true){
        int n;
        cin>>n;
        if(n==0){
            break;
        }
        cout<<fib[n]<<endl;
    }
    return 0;
}