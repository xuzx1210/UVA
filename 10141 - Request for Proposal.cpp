#include<iostream>
#include<string>
#include<cfloat>
using namespace std;
int main(){
    int t=0;
    while(true){
        int requirements, proposals;
        cin>>requirements>>proposals;
        if(requirements==0 && proposals==0){
            break;
        }
        if(t){
            cout<<endl;
        }
        ++t;
        string line;
        for(int i=0;i<=requirements;++i){
            getline(cin, line);
        }
        string name, result_name;
        float price, result_price=FLT_MAX;
        unsigned int item, result_item=0;
        for(int i=0;i<proposals;++i){
            getline(cin, name);
            cin>>price>>item;
            for(int j=0;j<=item;++j){
                getline(cin, line);
            }
            if(item>result_item){
                result_item=item;
                result_price=price;
                result_name=name;
            }else if(item==result_item){
                if(price<result_price){
                    result_price=price;
                    result_name=name;
                }
            }
        }
        cout<<"RFP #"<<t<<endl;
        cout<<result_name<<endl;
    }
    return 0;
}