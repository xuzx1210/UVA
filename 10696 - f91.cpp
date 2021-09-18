#include<iostream>
using namespace std;
int main(){
    while(true){
        int n;
        cin>>n;
        if(n==0){
            break;
        }
        cout<<"f91("<<n<<") = ";
        cout<<(n<101?91:(n-10))<<endl;
    }
    return 0;
}