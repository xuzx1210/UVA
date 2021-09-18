#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int t=0;t<n;++t){
        int size[3];
        vector<int> problem[3];
        for(int i=0;i<3;++i){
            problem[i].clear();
            cin>>size[i];
            for(int j=0;j<size[i];++j){
                int tmp;
                cin>>tmp;
                problem[i].push_back(tmp);
            }
            sort(problem[i].begin(), problem[i].end());
        }
        vector<int> only[3];
        for(int i=0;i<3;++i){
            only[i].clear();
            for(int j=0;j<size[i];++j){
                bool found=false;
                for(int k=0;k<3;++k){
                    if(i==k){
                        continue;
                    }
                    for(int l=0;l<size[k];++l){
                        if(problem[i][j]==problem[k][l]){
                            found=true;
                            break;
                        }
                    }
                    if(found){
                        break;
                    }
                }
                if(!found){
                    only[i].push_back(problem[i][j]);
                }
            }
        }
        int M=0;
        for(int i=0;i<3;++i){
            if(only[i].size()>M){
                M=only[i].size();
            }
        }
        vector<int> biggest;
        biggest.clear();
        for(int i=0;i<3;++i){
            if(M==only[i].size()){
                biggest.push_back(i);
            }
        }
        cout<<"Case #"<<t+1<<':'<<endl;
        for(int i=0;i<biggest.size();++i){
            cout<<biggest[i]+1<<' '<<only[biggest[i]].size();
            for(int j=0;j<only[biggest[i]].size();++j){
                cout<<' '<<only[biggest[i]][j];
            }
            cout<<endl;
        }
    }
    return 0;
}