#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<sstream>
using namespace std;
class Node{
public:
    int value;
    Node *left, *right;
    Node(){
        left=nullptr;
        right=nullptr;
    }
    void build(vector<int> &inOrder, stack<int> &postOrder){
        int len=inOrder.size();
        value=postOrder.top();
        postOrder.pop();
        int mid;
        for(int i=0;i<len;++i){
            if(inOrder[i]==value){
                mid=i;
                break;
            }
        }
        if(mid!=len-1){
            vector<int> rightSubtree(inOrder.begin()+mid+1, inOrder.end());
            right=new Node;
            right->build(rightSubtree, postOrder);
        }
        if(mid!=0){
            vector<int> leftSubtree(inOrder.begin(), inOrder.begin()+mid);
            left=new Node;
            left->build(leftSubtree, postOrder);
        }
    }
    pair<int, int> findMin(){
        if(left==nullptr && right==nullptr){
            return {value, value};
        }else if(left==nullptr){
            pair<int, int> m=right->findMin();
            return {m.first, m.second+value};
        }else if(right==nullptr){
            pair<int, int> m=left->findMin();
            return {m.first, m.second+value};
        }else{
            pair<int, int> leftMin=left->findMin(), rightMin=right->findMin();
            if(leftMin.second<rightMin.second){
                return {leftMin.first, leftMin.second+value};
            }else if(leftMin.second>rightMin.second){
                return {rightMin.first, rightMin.second+value};
            }else{
                if(leftMin.first<rightMin.first){
                    return {leftMin.first, leftMin.second+value};
                }else{
                    return {rightMin.first, rightMin.second+value};
                }
            }
        }
    }
    void release(){
        if(left!=nullptr){
            left->release();
            delete left;
        }
        if(right!=nullptr){
            right->release();
            delete right;
        }
    }
};
int main(){
    string in, post;
    while(getline(cin, in)){
        getline(cin, post);
        vector<int> inOrder;
        stack<int> postOrder;
        int tmp;
        stringstream ssIn(in), ssPost(post);
        while(ssIn>>tmp){
            inOrder.push_back(tmp);
        }
        while(ssPost>>tmp){
            postOrder.push(tmp);
        }
        Node *root;
        root=new Node;
        root->build(inOrder, postOrder);
        pair<int, int> m=root->findMin();
        cout<<m.first<<endl;
        root->release();
        delete root;
    }
    return 0;
}