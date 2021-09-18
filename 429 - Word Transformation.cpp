#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<queue>
#include<algorithm>
using namespace std;
typedef struct{
    int index;
    int depth;
}Node;
int main(){
    int n;
    cin>>n;
    for(int test=0;test<n;++test){
        vector<string> dict;
        string tmp;
        cin>>tmp;
        while(tmp!="*"){
            dict.push_back(tmp);
            cin>>tmp;
        }
        getline(cin, tmp);
        bool m[dict.size()][dict.size()];
        for(int i=0;i<dict.size();++i){
            m[i][i]=false;
        }
        for(int i=0;i<dict.size()-1;++i){
            for(int j=i+1;j<dict.size();++j){
                m[i][j]=false;
                m[j][i]=false;
                if(dict[i].length()==dict[j].length()){
                    int dif=0;
                    for(int k=0;k<dict[i].length();++k){
                        if(dict[i][k]!=dict[j][k]){
                            ++dif;
                        }
                    }
                    if(dif==1){
                        m[i][j]=true;
                        m[j][i]=true;
                    }
                }
            }
        }
        getline(cin, tmp);
        while(tmp!=""){
            stringstream ss;
            ss<<tmp;
            string left, right;
            ss>>left>>right;
            int start, end;
            for(int i=0;i<dict.size();++i){
                if(dict[i]==left){
                    start=i;
                    break;
                }
            }
            for(int i=0;i<dict.size();++i){
                if(dict[i]==right){
                    end=i;
                    break;
                }
            }
            vector<int> found;
            queue<Node> next;
            next.push({start, 0});
            found.push_back(start);
            cout<<left<<" "<<right<<" ";
            while(!next.empty()){
                Node cur=next.front();
                if(cur.index==end){
                    cout<<cur.depth<<endl;
                    break;
                }
                next.pop();
                for(int i=0;i<dict.size();++i){
                    if(m[cur.index][i]){
                        if(count(found.begin(), found.end(), i)==0){
                            next.push({i, cur.depth+1});
                            found.push_back(i);
                        }
                    }
                }
            }
            getline(cin, tmp);
        }
        if(test!=n-1){
            cout<<endl;
        }
    }
    return 0;
}