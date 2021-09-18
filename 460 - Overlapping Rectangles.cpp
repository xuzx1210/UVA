#include<iostream>
#include<algorithm>
using namespace std;
class Square{
private:
    class Point{
    public:
        int x, y;
    };
public:
    Point p1, p2;
};
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        Square a, b;
        cin>>a.p1.x>>a.p1.y>>a.p2.x>>a.p2.y>>b.p1.x>>b.p1.y>>b.p2.x>>b.p2.y;
        int x1=max(a.p1.x, b.p1.x), y1=max(a.p1.y, b.p1.y), x2=min(a.p2.x, b.p2.x), y2=min(a.p2.y, b.p2.y);
        if(x1>=x2 || y1>=y2){
            cout<<"No Overlap"<<endl;
        }else{
            cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
        }
        if(i<n-1){
            cout<<endl;
        }
    }
    return 0;
}