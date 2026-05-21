// kth level of Binary Tree

#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data ;
    Node* left ;
    Node* right ;
    Node(int val){
        data= val ;
        right = left = NULL ;
    }
};

static int idx = -1 ;
Node* buildTree(vector<int> vec){
    idx ++ ;
    if(vec[idx] == -1) return NULL ;
    Node* root = new Node(vec[idx]) ;
    root->left = buildTree(vec) ;
    root->right = buildTree(vec) ;
    return root ;
}

void kthLevel(Node* root , int k){
    if(root == NULL){
        return ;
    }
    if(k==1){
        cout << root->data << " " ;
        return ;
    }
    kthLevel(root->left , k-1) ;
    kthLevel(root->right , k-1) ;
}

int main(){
    vector<int> vec = {1,2,3,-1,-1,-1,4,5,-1,-1,6,-1,-1} ;
    Node* root = buildTree(vec) ;
    kthLevel(root , 3) ;
}