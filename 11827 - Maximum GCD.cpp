#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
int gcd(int a, int b){
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}
int main(){
    int n;
    cin>>n;
    string line;
    getline(cin, line);
    for(int t=0;t<n;++t){
        getline(cin, line);
        stringstream ss(line);
        vector<int> num;
        num.clear();
        int tmp;
        while(ss>>tmp){
            num.push_back(tmp);
        }
        int max=0;
        for(int i=0;i<num.size()-1;++i){
            for(int j=i+1;j<num.size();++j){
                int g=gcd(num[i], num[j]);
                if(g>max){
                    max=g;
                }
            }
        }
        cout<<max<<endl;
    }
    return 0;
}