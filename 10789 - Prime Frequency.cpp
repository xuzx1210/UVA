#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main(){
    bool prime[2001];
    prime[0]=false;
    prime[1]=false;
    for(int i=2;i<2001;++i){
        prime[i]=true;
    }
    for(int i=2;i<2001;++i){
        if(prime[i]){
            for(int j=(i<<1);j<2001;j+=i){
                prime[j]=false;
            }
        }
    }
    int testcase;
    cin>>testcase;
    for(int t=0;t<testcase;++t){
        string input;
        cin>>input;
        int digit[10], upper[26], lower[26];
        for(int i=0;i<10;++i){
            digit[i]=0;
        }
        for(int i=0;i<26;++i){
            upper[i]=0;
            lower[i]=0;
        }
        for(int i=0;i<input.length();++i){
            if(isupper(input[i])){
                ++upper[input[i]-'A'];
            }else if(islower(input[i])){
                ++lower[input[i]-'a'];
            }else{
                ++digit[input[i]-'0'];
            }
        }
        bool printed=false;
        cout<<"Case "<<t+1<<": ";
        for(int i=0;i<10;++i){
            if(prime[digit[i]]){
                cout<<i;
                printed=true;
            }
        }
        for(int i=0;i<26;++i){
            if(prime[upper[i]]){
                cout<<(char)('A'+i);
                printed=true;
            }
        }
        for(int i=0;i<26;++i){
            if(prime[lower[i]]){
                cout<<(char)('a'+i);
                printed=true;
            }
        }
        if(!printed){
            cout<<"empty";
        }
        cout<<endl;
    }
    return 0;
}