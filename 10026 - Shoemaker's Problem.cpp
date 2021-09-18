#include<iostream>
#include<algorithm>
using namespace std;
class Work{
public:
    int index, duration, fine;
    bool operator<(Work right){
        float ratioA=(float)fine/(float)duration, ratioB=(float)right.fine/(float)right.duration;
        if(ratioA>ratioB){
            return true;
        }else if(ratioA<ratioB){
            return false;
        }else{
            if(index<right.index){
                return true;
            }else{
                return false;
            }
        }
    }
};
int main(){
    int n;
    cin>>n;
    for(int t=0;t<n;++t){
        if(t){
            cout<<endl;
        }
        int works;
        cin>>works;
        Work work[works];
        for(int i=0;i<works;++i){
            work[i].index=i+1;
            cin>>work[i].duration>>work[i].fine;
        }
        sort(work, work+works);
        cout<<work[0].index;
        for(int i=1;i<works;++i){
            cout<<' '<<work[i].index;
        }
        cout<<endl;
    }
    return 0;
}