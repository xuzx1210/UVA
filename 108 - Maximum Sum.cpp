#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    int num[n][n];
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>num[i][j];
        }
    }
    int acc[n][n];
    acc[0][0]=num[0][0];
    for(int i=1;i<n;++i){
        acc[i][0]=acc[i-1][0]+num[i][0];
        acc[0][i]=acc[0][i-1]+num[0][i];
    }
    for(int i=1;i<n;++i){
        for(int j=1;j<n;++j){
            acc[i][j]=num[i][j]+acc[i-1][j]+acc[i][j-1]-acc[i-1][j-1];
        }
    }
    int max=INT_MIN;
    for(int x1=0;x1<n;++x1){
        for(int y1=0;y1<n;++y1){
            for(int x2=x1;x2<n;++x2){
                for(int y2=y1;y2<n;++y2){
                    int sum=acc[x2][y2];
                    if(x1!=0 && y1!=0){
                        sum=sum-acc[x2][y1-1]-acc[x1-1][y2]+acc[x1-1][y1-1];
                    }else if(x1==0 && y1!=0){
                        sum=sum-acc[x2][y1-1];
                    }else if(x1!=0 && y1==0){
                        sum=sum-acc[x1-1][y2];
                    }
                    if(sum>max){
                        max=sum;
                    }
                }
            }
        }
    }
    cout<<max<<endl;
    return 0;
}