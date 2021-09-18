#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    string one="one", two="two";
    for(int t=0;t<n;++t){
        string word;
        cin>>word;
        if(word.length()==5){
            cout<<'3'<<endl;
            continue;
        }
        int diff=0;
        for(int i=0;i<3;++i){
            if(one[i]!=word[i]){
                ++diff;
            }
        }
        cout<<(diff<=1?'1':'2')<<endl;
    }
    return 0;
}