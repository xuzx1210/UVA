#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class Node{
public:
    Node(){
        x=0;
        y=0;
    }
    Node(int a, int b){
        x=a;
        y=b;
    }
    bool inRange(){
        if(0<=x && x<=7 && 0<=y && y<=7){
            return true;
        }else{
            return false;
        }
    }
    Node operator+(const Node &right){
        Node result(this->x+right.x, this->y+right.y);
        return result;
    }
    bool operator==(const Node &right){
        if(this->x==right.x && this->y==right.y){
            return true;
        }else{
            return false;
        }
    }
    int x;
    int y;
};
int main(){
    Node move[8]={{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    char x1, x2;
    int y1, y2;
    while(cin>>x1>>y1>>x2>>y2){
        Node start(x1-'a', y1-1), end(x2-'a', y2-1);
        queue<pair<Node, int>> next;
        vector<Node> found;
        next.push({start, 0});
        found.push_back(start);
        while(!next.empty()){
            Node cur=next.front().first;
            int depth=next.front().second;
            if(cur==end){
                cout<<"To get from "<<x1<<y1<<" to "<<x2<<y2<<" takes "<<depth<<" knight moves."<<endl;
                break;
            }
            next.pop();
            for(int i=0;i<8;++i){
                Node tmp=cur+move[i];
                if(tmp.inRange() && count(found.begin(), found.end(), tmp)==0){
                    next.push({tmp, depth+1});
                    found.push_back(tmp);
                }
            }
        }
    }
    return 0;
}