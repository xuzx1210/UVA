#include<iostream>
using namespace std;
int main(){
    int coe[9];
    while(cin>>coe[8]){
        for(int i=7;i>=0;--i){
            cin>>coe[i];
        }
        int first=9;
        for(int i=8;i>=0;--i){
            if(coe[i]){
                first=i;
                break;
            }
        }
        if(first==9){
            cout<<"0"<<endl;
            continue;
        }
        bool neg[9];
        for(int i=0;i<9;++i){
            neg[i]=false;
            if(coe[i]<0){
                neg[i]=true;
                coe[i]=-coe[i];
            }
        }
        if(neg[first]){
            cout<<"-";
        }
        if(coe[first]!=1){
            cout<<coe[first];
        }else if(first==0){
            cout<<"1";
        }
        if(first>1){
            cout<<"x^"<<first;
        }else if(first==1){
            cout<<"x";
        }
        for(int i=first-1;i>=0;--i){
            if(coe[i]==0){
                continue;
            }
            cout<<" "<<(neg[i]?"-":"+")<<" ";
            if(coe[i]!=1){
                cout<<coe[i];
            }else if(i==0){
                cout<<"1";
            }
            if(i>1){
                cout<<"x^"<<i;
            }else if(i==1){
                cout<<"x";
            }
        }
        cout<<endl;
    }
    return 0;
}