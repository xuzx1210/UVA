#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<sstream>
using namespace std;
void dfs(bool *map, const int n, const int m, bool *used, const int i, const int j){
    used[i*m+j]=true;
    for(int a=-1;a<=1;++a){
        if(i+a>=n || i+a<0){
            continue;
        }
        for(int b=-1;b<=1;++b){
            if(a==0 && b==0){
                continue;
            }
            if(j+b>=0 && j+b<m){
                if(!used[(i+a)*m+(j+b)] && map[(i+a)*m+(j+b)]){
                    dfs(map, n, m, used, i+a, j+b);
                }
            }
        }
    }
}
int count(bool *map, const int n, const int m, const int i, const int j){
    bool used[n*m]={false};
    dfs(map, n, m, used, i, j);
    int result=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(map[i*m+j] && used[i*m+j]){
                ++result;
            }
        }
    }
    return result;
}
int main(){
    int N;
    cin>>N;
    string line;
    getline(cin, line);
    getline(cin, line);
    for(int t=0;t<N;++t){
        if(t){
            cout<<endl;
        }
        int n, m;
        vector<string> tmp;
        while(true){
            getline(cin, line);
            if(isdigit(line[0])){
                break;
            }
            tmp.push_back(line);
        }
        n=tmp.size();
        m=tmp[0].length();
        bool map[n*m];
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                map[i*m+j]=(tmp[i][j]=='W');
            }
        }
        while(true){
            stringstream ss;
            ss<<line;
            int r, c;
            ss>>r>>c;
            cout<<count(map, n, m, r-1, c-1)<<endl;
            getline(cin, line);
            if(line==""){
                break;
            }
        }
    }
    return 0;
}