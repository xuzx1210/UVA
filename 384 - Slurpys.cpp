#include<iostream>
#include<string>
using namespace std;
bool slump(string &word){
    int len=word.length();
    if(len<3){
        return false;
    }
    if(!(word[0]=='D' || word[0]=='E')){
        return false;
    }
    if(word[1]!='F'){
        return false;
    }
    int pos=0;
    for(int i=2;i<len;++i){
        if(word[i]!='F'){
            pos=i;
            break;
        }
    }
    if(pos==0){
        return false;
    }
    string next(word, pos, len-pos);
    if(next=="G"){
        return true;
    }else{
        return slump(next);
    }
}
bool slimp(string &word){
    int len=word.length();
    if(len<2){
        return false;
    }
    if(len==2){
        return (word=="AH");
    }
    if(word[len-1]!='C'){
        return false;
    }
    if(word[1]=='B'){
        string next(word, 2, len-3);
        return slimp(next);
    }else{
        string next(word, 1, len-2);
        return slump(next);
    }
}
bool slurpy(string &word){
    int len=word.length();
    for(int i=0;i<len;++i){
        if(word[i]=='D' || word[i]=='E'){
            string a(word, 0, i), b(word, i, len-i);
            if(i<(len>>1)){
                if(slimp(a)){
                    if(slump(b)){
                        return true;
                    }
                }
            }else{
                if(slump(b)){
                    if(slimp(a)){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    cout<<"SLURPYS OUTPUT"<<endl;
    for(int i=0;i<n;++i){
        string word;
        cin>>word;
        if(slurpy(word)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    cout<<"END OF OUTPUT"<<endl;
    return 0;
}