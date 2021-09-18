#include<iostream>
#include<string>
using namespace std;
int main(){
    string first, second;
    while(getline(cin, first)){
        getline(cin, second);
        int table[first.length()+1][second.length()+1];
        for(int i=0;i<=first.length();++i){
            table[i][0]=0;
        }
        for(int i=0;i<=second.length();++i){
            table[0][i]=0;
        }
        for(int i=1;i<=first.length();++i){
            for(int j=1;j<=second.length();++j){
                if(first[i-1]==second[j-1]){
                    table[i][j]=table[i-1][j-1]+1;
                }else{
                    if(table[i][j-1]>table[i-1][j]){
                        table[i][j]=table[i][j-1];
                    }else{
                        table[i][j]=table[i-1][j];
                    }
                }
            }
        }
        cout<<table[first.length()][second.length()]<<endl;
    }
    return 0;
}