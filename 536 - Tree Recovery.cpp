#include<iostream>
#include<queue>
#include<string>
using namespace std;
class Node{
public:
    Node(){
        left=nullptr;
        right=nullptr;
    }
    char alphabet;
    Node *left, *right;
    void build(queue<char> &preorder, string &subtree){
        int len=subtree.length();
        alphabet=preorder.front();
        preorder.pop();
        int mid;
        for(int i=0;i<len;++i){
            if(subtree[i]==alphabet){
                mid=i;
                break;
            }
        }
        if(mid!=0){
            string leftSubtree(subtree, 0, mid);
            left=new Node;
            left->build(preorder, leftSubtree);
        }
        if(mid!=len-1){
            string rightSubtree(subtree, mid+1, len-mid-1);
            right=new Node;
            right->build(preorder, rightSubtree);
        }
    }
    void print(){
        if(left!=nullptr){
            left->print();
        }
        if(right!=nullptr){
            right->print();
        }
        cout<<alphabet;
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
    string pre, in;
    while(cin>>pre>>in){
        queue<char> preorder;
        for(int i=0;i<pre.length();++i){
            preorder.push(pre[i]);
        }
        Node *root;
        root=new Node;
        root->build(preorder, in);
        root->print();
        cout<<endl;
        root->release();
        delete root;
    }
    return 0;
}