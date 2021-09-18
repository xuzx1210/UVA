#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int round;
    while(cin>>round){
        if(round==-1){
            break;
        }
        cout<<"Round "<<round<<"\nYou ";
        string solution, guess;
        cin>>solution>>guess;
        vector<char> sol;
        for(int i=0;i<solution.length();++i){
            if(count(sol.begin(), sol.end(), solution[i])==0){
                sol.push_back(solution[i]);
            }
        }
        int success=0, fail=0;
        vector<char> guessed;
        bool over=false;
        for(int i=0;i<guess.length();++i){
            char cur=guess[i];
            if(count(sol.begin(), sol.end(), cur)){
                if(count(guessed.begin(), guessed.end(), cur)==0){
                    ++success;
                    guessed.push_back(cur);
                }
            }else{
                if(count(guessed.begin(), guessed.end(), cur)==0){
                    ++fail;
                    guessed.push_back(cur);
                }
            }
            if(success==sol.size()){
                cout<<"win."<<endl;
                over=true;
                break;
            }
            if(fail==7){
                cout<<"lose."<<endl;
                over=true;
                break;
            }
        }
        if(!over){
            cout<<"chickened out."<<endl;
        }
    }
    return 0;
}