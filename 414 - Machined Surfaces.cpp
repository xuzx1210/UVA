#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n){
        string line;
        getline(cin, line);
        int x[n], max=0;
        for(int i=0;i<n;++i){
            getline(cin, line);
            int count=0;
            for(int j=0;j<25;++j){
                if(line[j]=='X'){
                    ++count;
                }
            }
            x[i]=count;
            if(count>max){
                max=count;
            }
        }
        int b=0;
        for(int i=0;i<n;++i){
            b+=(max-x[i]);
        }
        cout<<b<<endl;
        cin>>n;
    }
    return 0;
}