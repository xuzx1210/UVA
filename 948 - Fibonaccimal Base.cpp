#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> fibonacci;
    fibonacci.clear();
    fibonacci.push_back(1);
    fibonacci.push_back(2);
    while(fibonacci[fibonacci.size()-1]<100000000){
        fibonacci.push_back(fibonacci[fibonacci.size()-2]+fibonacci[fibonacci.size()-1]);
    }
    int n;
    cin>>n;
    for(int testCase=0;testCase<n;++testCase){
        int num;
        cin>>num;
        cout<<num<<" = ";
        bool base[fibonacci.size()];
        for(int i=0;i<fibonacci.size();++i){
            base[i]=false;
        }
        for(int i=fibonacci.size()-1;i>=0;--i){
            if(num>=fibonacci[i]){
                base[i]=true;
                num-=fibonacci[i];
            }
        }
        int start;
        for(int i=fibonacci.size()-1;i>=0;--i){
            if(base[i]){
                start=i;
                break;
            }
        }
        for(int i=start;i>=0;--i){
            if(base[i]){
                cout<<"1";
            }else{
                cout<<"0";
            }
        }
        cout<<" (fib)"<<endl;
    }
    return 0;
}