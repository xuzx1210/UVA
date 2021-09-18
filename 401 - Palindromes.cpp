#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
string mirror(string &word, map<char, char> &m){
    string result(word);
    reverse(result.begin(), result.end());
    for(int i=0;i<word.length();++i){
        result[i]=m[result[i]];
    }
    return result;
}
int main(){
    map<char, char> m;
    m.insert(pair<char, char>('A', 'A'));
    m.insert(pair<char, char>('B', ' '));
    m.insert(pair<char, char>('C', ' '));
    m.insert(pair<char, char>('D', ' '));
    m.insert(pair<char, char>('E', '3'));
    m.insert(pair<char, char>('F', ' '));
    m.insert(pair<char, char>('G', ' '));
    m.insert(pair<char, char>('H', 'H'));
    m.insert(pair<char, char>('I', 'I'));
    m.insert(pair<char, char>('J', 'L'));
    m.insert(pair<char, char>('K', ' '));
    m.insert(pair<char, char>('L', 'J'));
    m.insert(pair<char, char>('M', 'M'));
    m.insert(pair<char, char>('N', ' '));
    m.insert(pair<char, char>('O', 'O'));
    m.insert(pair<char, char>('P', ' '));
    m.insert(pair<char, char>('Q', ' '));
    m.insert(pair<char, char>('R', ' '));
    m.insert(pair<char, char>('S', '2'));
    m.insert(pair<char, char>('T', 'T'));
    m.insert(pair<char, char>('U', 'U'));
    m.insert(pair<char, char>('V', 'V'));
    m.insert(pair<char, char>('W', 'W'));
    m.insert(pair<char, char>('X', 'X'));
    m.insert(pair<char, char>('Y', 'Y'));
    m.insert(pair<char, char>('Z', '5'));
    m.insert(pair<char, char>('1', '1'));
    m.insert(pair<char, char>('2', 'S'));
    m.insert(pair<char, char>('3', 'E'));
    m.insert(pair<char, char>('4', ' '));
    m.insert(pair<char, char>('5', 'Z'));
    m.insert(pair<char, char>('6', ' '));
    m.insert(pair<char, char>('7', ' '));
    m.insert(pair<char, char>('8', '8'));
    m.insert(pair<char, char>('9', ' '));
    string word;
    while(cin>>word){
        string reverseWord(word), mirrorWord=mirror(word, m);
        reverse(reverseWord.begin(), reverseWord.end());
        cout<<word<<" -- is ";
        if(word==reverseWord){
            if(word==mirrorWord){
                cout<<"a mirrored palindrome."<<endl;
            }else{
                cout<<"a regular palindrome."<<endl;
            }
        }else{
            if(word==mirrorWord){
                cout<<"a mirrored string."<<endl;
            }else{
                cout<<"not a palindrome."<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}