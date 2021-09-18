#include<iostream>
#include<map>
using namespace std;
map<char, int> c, n;
class Hand{
public:
    class Card{
    public:
        char color, number;
        bool operator>(Card &right){
            if(c[color]>c[right.color]){
                return true;
            }else if(c[color]<c[right.color]){
                return false;
            }else{
                if(n[number]>n[right.number]){
                    return true;
                }else{
                    return false;
                }
            }
        }
    };
    Card card[13];
    void sort(){
        for(int i=0;i<12;++i){
            for(int j=i+1;j<13;++j){
                if(card[i]>card[j]){
                    Card tmp=card[i];
                    card[i]=card[j];
                    card[j]=tmp;
                }
            }
        }
    }
};

int main(){
    c.clear();
    c['C']=0;
    c['D']=1;
    c['S']=2;
    c['H']=3;
    n.clear();
    n['2']=0;
    n['3']=1;
    n['4']=2;
    n['5']=3;
    n['6']=4;
    n['7']=5;
    n['8']=6;
    n['9']=7;
    n['T']=8;
    n['J']=9;
    n['Q']=10;
    n['K']=11;
    n['A']=12;
    while(true){
        char d;
        cin>>d;
        if(d=='#'){
            break;
        }
        Hand S, W, N, E;
        if(d=='N'){
            for(int i=0;i<13;++i){
                cin>>E.card[i].color>>E.card[i].number;
                cin>>S.card[i].color>>S.card[i].number;
                cin>>W.card[i].color>>W.card[i].number;
                cin>>N.card[i].color>>N.card[i].number;
            }
        }else if(d=='E'){
            for(int i=0;i<13;++i){
                cin>>S.card[i].color>>S.card[i].number;
                cin>>W.card[i].color>>W.card[i].number;
                cin>>N.card[i].color>>N.card[i].number;
                cin>>E.card[i].color>>E.card[i].number;
            }
        }else if(d=='S'){
            for(int i=0;i<13;++i){
                cin>>W.card[i].color>>W.card[i].number;
                cin>>N.card[i].color>>N.card[i].number;
                cin>>E.card[i].color>>E.card[i].number;
                cin>>S.card[i].color>>S.card[i].number;
            }
        }else{
            for(int i=0;i<13;++i){
                cin>>N.card[i].color>>N.card[i].number;
                cin>>E.card[i].color>>E.card[i].number;
                cin>>S.card[i].color>>S.card[i].number;
                cin>>W.card[i].color>>W.card[i].number;
            }
        }
        S.sort();
        W.sort();
        N.sort();
        E.sort();
        cout<<"S:";
        for(int i=0;i<13;++i){
            cout<<" "<<S.card[i].color<<S.card[i].number;
        }
        cout<<endl;
        cout<<"W:";
        for(int i=0;i<13;++i){
            cout<<" "<<W.card[i].color<<W.card[i].number;
        }
        cout<<endl;
        cout<<"N:";
        for(int i=0;i<13;++i){
            cout<<" "<<N.card[i].color<<N.card[i].number;
        }
        cout<<endl;
        cout<<"E:";
        for(int i=0;i<13;++i){
            cout<<" "<<E.card[i].color<<E.card[i].number;
        }
        cout<<endl;
    }
    return 0;
}