#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
typedef unsigned long long int ulli;
int main(){
    string line;
    getline(cin, line);
    while(line[0]!='#'){
        ulli crc=0;
        for(int i=0;i<line.length();++i){
            crc=((crc<<8)+line[i])%34943;
        }
        crc=(34943-(crc<<16)%34943)%34943;
        printf("%02X %02X\n", crc>>8, crc&255);
        getline(cin, line);
    }
    return 0;
}