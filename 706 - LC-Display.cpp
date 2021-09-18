#include<iostream>
#include<string>
using namespace std;
int main(){
    bool seven_segment[10][7]={{true, true, true, false, true, true, true}, 
                                {false, false, true, false, false, true, false}, 
                                {true, false, true, true, true, false, true}, 
                                {true, false, true, true, false, true, true}, 
                                {false, true, true, true, false, true, false}, 
                                {true, true, false, true, false, true, true}, 
                                {true, true, false, true, true, true, true}, 
                                {true, false, true, false, false, true, false}, 
                                {true, true, true, true, true, true, true}, 
                                {true, true, true, true, false, true, true}};
    while(true){
        int s;
        string n;
        cin>>s>>n;
        if(s==0 && n=="0"){
            break;
        }
        for(int num=0;num<n.length();++num){
            if(num){
                cout<<' ';
            }
            int index=n[num]-'0';
            cout<<' ';
            for(int i=0;i<s;++i){
                cout<<(seven_segment[index][0]?'-':' ');
            }
            cout<<' ';
        }
        cout<<endl;
        for(int i=0;i<s;++i){
            for(int num=0;num<n.length();++num){
                if(num){
                    cout<<' ';
                }
                int index=n[num]-'0';
                cout<<(seven_segment[index][1]?'|':' ');
                for(int j=0;j<s;++j){
                    cout<<' ';
                }
                cout<<(seven_segment[index][2]?'|':' ');
            }
            cout<<endl;
        }
        for(int num=0;num<n.length();++num){
            if(num){
                cout<<' ';
            }
            int index=n[num]-'0';
            cout<<' ';
            for(int i=0;i<s;++i){
                cout<<(seven_segment[index][3]?'-':' ');
            }
            cout<<' ';
        }
        cout<<endl;
        for(int i=0;i<s;++i){
            for(int num=0;num<n.length();++num){
                if(num){
                    cout<<' ';
                }
                int index=n[num]-'0';
                cout<<(seven_segment[index][4]?'|':' ');
                for(int j=0;j<s;++j){
                    cout<<' ';
                }
                cout<<(seven_segment[index][5]?'|':' ');
            }
            cout<<endl;
        }
        for(int num=0;num<n.length();++num){
            if(num){
                cout<<' ';
            }
            int index=n[num]-'0';
            cout<<' ';
            for(int i=0;i<s;++i){
                cout<<(seven_segment[index][6]?'-':' ');
            }
            cout<<' ';
        }
        cout<<endl<<endl;
    }
    return 0;
}