#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> prime;
    prime.push_back(1);
    for(int i=2;i<=1000;++i){
        bool c=false;
        for(int j=1;j<prime.size();++j){
            if(i%prime[j]==0){
                c=true;
                break;
            }
        }
        if(!c){
            prime.push_back(i);
        }
    }
    int n, c;
    while(cin>>n>>c){
        int k=prime.size();
        for(int i=0;i<prime.size();++i){
            if(prime[i]>n){
                k=i;
                break;
            }
        }
        cout<<n<<" "<<c<<":";
        if(k&1){
            if((c<<1)-1>=k){
                for(int i=0;i<k;++i){
                    cout<<" "<<prime[i];
                }
            }else{
                int m=(k-1)>>1;
                for(int i=m-c+1;i<m+c;++i){
                    cout<<" "<<prime[i];
                }
            }
        }else{
            if((c<<1)>=k){
                for(int i=0;i<k;++i){
                    cout<<" "<<prime[i];
                }
            }else{
                int m=k>>1;
                for(int i=m-c;i<m+c;++i){
                    cout<<" "<<prime[i];
                }
            }
        }
        cout<<endl<<endl;
    }
    return 0;
}