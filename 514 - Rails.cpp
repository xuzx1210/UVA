#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int main(){
    while(true){
        int n;
        cin>>n;
        if(n==0){
            break;
        }
        while(true){
            int input;
            cin>>input;
            if(input==0){
                cout<<endl;
                break;
            }
            queue<int> in, out;
            while(!in.empty()){
                in.pop();
            }
            for(int i=1;i<=n;++i){
                in.push(i);
            }
            while(!out.empty()){
                out.pop();
            }
            out.push(input);
            for(int i=1;i<n;++i){
                cin>>input;
                out.push(input);
            }
            stack<int> station;
            while(!station.empty()){
                station.pop();
            }
            bool possible=true;
            while(!out.empty()){
                if(in.empty() && station.top()!=out.front()){
                    possible=false;
                    break;
                }
                bool action=false;
                if(!in.empty()){
                    if(in.front()==out.front()){
                        in.pop();
                        out.pop();
                        action=true;
                    }
                }
                if(action){
                    continue;
                }
                if(!station.empty()){
                    if(station.top()==out.front()){
                        station.pop();
                        out.pop();
                        action=true;
                    }
                }
                if(action){
                    continue;
                }
                station.push(in.front());
                in.pop();
            }
            cout<<(possible?"Yes":"No")<<endl;
        }
    }
    return 0;
}