// Lowest Common Ancestor of BST ( Leetcode -> 235 )

#include<iostream>
#include<vector>
using namespace std ;

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

static int idx = -1 ;
Node* buildTree(vector<int> vec){
    idx++ ;
    if(vec[idx] == -1 ) return NULL ;
    Node* root = new Node(vec[idx]) ;
    root->left = buildTree(vec) ;
    root->right = buildTree(vec) ;
    return root ;
}

void inOrder(Node* root){
    if(root == NULL ) return ;
    inOrder(root->left) ;
    cout << root->data << " " ;
    inOrder(root->right) ;
    return ;
}

// Time complexity =  O(Height of tree) = O(log n) 
Node* leastCommonAncestor(Node* root ,int p , int q){
    if(root == NULL) return NULL ;

    if(root->data > p && root->data > q ){
        leastCommonAncestor(root->left , p , q) ;
    }
    else if(root->data < p && root->data < q ){
        leastCommonAncestor(root->right , p , q) ;
    }else{
        return root ;
    }
}

int main(){
    vector<int> vec = {6,2,0,-1,-1,4,3,-1,-1,5,-1,-1,8,7,-1,-1,9,-1,-1} ;
    Node* root = buildTree(vec) ;

    Node* LCA = leastCommonAncestor(root , 0 , 5) ;
    cout << "Least Common Ancestor is : " << LCA->data << endl ;
}