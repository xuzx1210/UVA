#include<iostream>
using namespace std;
int main(){
    while(true){
        int n;
        cin>>n;
        if(n==0){
            break;
        }
        int row[n], col[n], rowError=0, colError=0;
        for(int i=0;i<n;++i){
            row[i]=0;
            col[i]=0;
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                int tmp;
                cin>>tmp;
                row[i]+=tmp;
                col[j]+=tmp;
            }
        }
        for(int i=0;i<n;++i){
            rowError+=(row[i]&1);
            colError+=(col[i]&1);
        }
        if(rowError==0 && colError==0){
            cout<<"OK"<<endl;
        }else if(rowError==1 && colError==1){
            cout<<"Change bit (";
            for(int i=0;i<n;++i){
                if(row[i]&1){
                    cout<<i+1;
                    break;
                }
            }
            cout<<",";
            for(int i=0;i<n;++i){
                if(col[i]&1){
                    cout<<i+1;
                    break;
                }
            }
            cout<<")"<<endl;
        }else{
            cout<<"Corrupt"<<endl;
        }
    }
    return 0;
}