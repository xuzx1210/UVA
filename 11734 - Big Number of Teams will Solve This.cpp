#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    string line;
    getline(cin, line);
    for(int t=0;t<n;++t){
        string a, b;
        getline(cin, a);
        getline(cin, b);
        cout<<"Case "<<t+1<<": ";
        if(a==b){
            cout<<"Yes"<<endl;
            continue;
        }
        for(int i=a.length()-1;i>=0;--i){
            if(a[i]==' '){
                a.erase(a.begin()+i);
            }
        }
        for(int i=b.length()-1;i>=0;--i){
            if(b[i]==' '){
                b.erase(b.begin()+i);
            }
        }
        if(a==b){
            cout<<"Output Format Error"<<endl;
        }else{
            cout<<"Wrong Answer"<<endl;
        }
    }
    return 0;
}