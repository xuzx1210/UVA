#include<iostream>
#include<iomanip>
#include<stack>
using namespace std;
char number[]="A23456789TJQK";
char color[]="HDCS";
typedef struct{
	int n;
	int c;
}Card;
int num(char c){
	for(int i=0;i<13;i++){
		if(c==number[i]){
			return i;
		}
	}
}
int col(char c){
	for(int i=0;i<4;i++){
		if(c==color[i]){
			return i;
		}
	}
}
int main(){
	string card;
	while(cin>>card){
		if(card=="#"){
			break;
		}
		stack<Card> stacks[13];
		Card cards[52];
		cards[0].n=num(card[0]);
		cards[0].c=col(card[1]);
		for(int i=1;i<52;i++){
			cin>>card;
			cards[i].n=num(card[0]);
			cards[i].c=col(card[1]);
		}
		for(int i=51;i>=0;i--){
			stacks[12-i%13].push(cards[i]);
		}
		Card tmp=stacks[12].top();
		stacks[12].pop();
		int count=1;
		int next=tmp.n;
		while(!stacks[next].empty()){
			tmp=stacks[next].top();
			stacks[next].pop();
			next=tmp.n;
			count++;
		}
		cout<<setw(2)<<setfill('0')<<count<<","<<number[tmp.n]<<color[tmp.c]<<endl;
	}
	return 0;
}
