// Construct a tree from preorder and postorder (Leetcode -> 105)

#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data ;
    Node* left ;
    Node* right ;
    Node(int val){
        data = val ;
        left = right = NULL ;
    }
};

int search(vector<int> inorder , int left , int right , int val){
    for(int i = left ; i <= right ; i++){
        if(val == inorder[i]){
            return i ;
        }
    }
    return -1 ;
}

Node* buildTree(vector<int> &preOrder , vector<int> &inOrder , int &preIdx , int left , int right){
    if(left > right ) return NULL ;

    Node* root = new Node(preOrder[preIdx]) ;
    int inIdx = search(inOrder , left , right , preOrder[preIdx]) ;
    preIdx++ ;
    root->left = buildTree(preOrder , inOrder , preIdx , left , inIdx-1) ;
    root->right = buildTree(preOrder , inOrder , preIdx , inIdx+1 , right) ;
    return root ;
}

int main(){
    vector<int> preOrder = {3,9,20,15,7} ;
    vector<int> inOrder = {9,3,15,20,7} ;
    int preIdx = 0 ;
    Node* root = buildTree(preOrder , inOrder , preIdx , 0 , inOrder.size()-1);
}