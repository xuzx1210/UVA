#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
template<typename T>
class teamQueue{
private:
    vector<queue<T>> tq;
public:
    void push(T element, map<T, int> &team){
        T t=team[element];
        bool pushed=false;
        for(int i=0;i<tq.size();++i){
            if(team[tq[i].front()]==t){
                tq[i].push(element);
                pushed=true;
                break;
            }
        }
        if(!pushed){
            queue<T> tmp;
            tmp.push(element);
            tq.push_back(tmp);
        }
    }
    T pop(){
        T result=tq[0].front();
        tq[0].pop();
        if(tq[0].empty()){
            tq.erase(tq.begin());
        }
        return result;
    }
};
int main(){
    int time=0;
    while(true){
        int numberOfTeams;
        cin>>numberOfTeams;
        if(numberOfTeams==0){
            break;
        }
        map<int, int> team;
        for(int i=0;i<numberOfTeams;++i){
            int teamSize;
            cin>>teamSize;
            for(int j=0;j<teamSize;++j){
                int element;
                cin>>element;
                team[element]=i;
            }
        }
        teamQueue<int> line;
        string command;
        ++time;
        cout<<"Scenario #"<<time<<endl;
        while(true){
            cin>>command;
            if(command=="ENQUEUE"){
                int element;
                cin>>element;
                line.push(element, team);
            }else if(command=="DEQUEUE"){
                cout<<line.pop()<<endl;
            }else{
                cout<<endl;
                break;
            }
        }
    }
    return 0;
}