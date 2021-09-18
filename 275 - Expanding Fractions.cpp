#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    while(true){
        int dividend, divisor;
        cin>>dividend>>divisor;
        if(dividend==0 && divisor==0){
            break;
        }
        dividend%=divisor;
        vector<int> quotient;
        quotient.clear();
        vector<int> remainder;
        remainder.clear();
        int len;
        while(dividend){
            vector<int>::iterator start=find(remainder.begin(), remainder.end(), dividend);
            if(start!=remainder.end()){
                len=remainder.end()-start;
                break;
            }
            remainder.push_back(dividend);
            dividend*=10;
            quotient.push_back(dividend/divisor);
            dividend%=divisor;
        }
        cout<<'.';
        for(int i=0;i<quotient.size();++i){
            if(((i+1)%50)==0){
                cout<<endl;
            }
            cout<<quotient[i];
        }
        cout<<endl;
        if(dividend){
            cout<<"The last "<<len<<" digits repeat forever."<<endl;
        }else{
            cout<<"This expansion terminates."<<endl;
        }
        cout<<endl;
    }
    return 0;
}