// Lowest Common Ancestor (Leetcode -> 236)

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
    if(vec[idx] == -1) return NULL ;
    Node * root = new Node(vec[idx]) ;
    root->left = buildTree(vec) ;
    root->right = buildTree(vec) ;
    return root ;
}

Node* lowestCommonAncestor(Node* root , int p , int q){
    if(root == NULL){
        return NULL ;
    }

    if(root->data == p || root->data == q){
        return root ;
    }

    Node* lfLCA = lowestCommonAncestor(root->left , p , q) ;
    Node* rgLCA = lowestCommonAncestor(root->right , p , q) ;

    if(lfLCA && rgLCA){
        return root ;
    }else if( lfLCA != NULL ){
        return lfLCA ;
    }else{
        return rgLCA ;
    }

}

int main(){
    vector<int> vec = {1,2,4,-1,-1,5,8,-1,-1,9,-1,-1,3,6,-1,-1,7,-1,-1} ;
    Node* root = buildTree(vec) ;
    Node* LCA = lowestCommonAncestor(root , 4 , 9 );
    cout << "Lowest common ancestor is " << LCA->data ;
}