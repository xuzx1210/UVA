#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
int main(){
    string card;
    cin>>card;
    while(card!="#"){
        vector<stack<string>> cards;
        for(int i=0;i<51;++i){
            stack<string> tmp;
            tmp.push(card);
            cards.push_back(tmp);
            cin>>card;
        }
        stack<string> tmpStack;
        tmpStack.push(card);
        cards.push_back(tmpStack);
        bool change=true;
        while(change){
            change=false;
            for(int i=1;i<cards.size();++i){
                if(i<3){
                    if(cards[i].top()[0]==cards[i-1].top()[0] || cards[i].top()[1]==cards[i-1].top()[1]){
                        change=true;
                        cards[i-1].push(cards[i].top());
                        cards[i].pop();
                        if(cards[i].empty()){
                            cards.erase(cards.begin()+i);
                        }
                        break;
                    }
                }else{
                    if(cards[i].top()[0]==cards[i-3].top()[0] || cards[i].top()[1]==cards[i-3].top()[1]){
                        change=true;
                        cards[i-3].push(cards[i].top());
                        cards[i].pop();
                        if(cards[i].empty()){
                            cards.erase(cards.begin()+i);
                        }
                        break;
                    }else if(cards[i].top()[0]==cards[i-1].top()[0] || cards[i].top()[1]==cards[i-1].top()[1]){
                        change=true;
                        cards[i-1].push(cards[i].top());
                        cards[i].pop();
                        if(cards[i].empty()){
                            cards.erase(cards.begin()+i);
                        }
                        break;
                    }
                }
            }
        }
        if(cards.size()==1){
            cout<<"1 pile remaining:";
        }else{
            cout<<cards.size()<<" piles remaining:";
        }
        for(int i=0;i<cards.size();++i){
            cout<<" "<<cards[i].size();
        }
        cout<<endl;
        cin>>card;
    }
    return 0;
}