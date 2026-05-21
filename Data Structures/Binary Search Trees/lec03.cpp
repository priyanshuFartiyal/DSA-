// Validate BST ( Leetcode -> 98 )

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
    Node* root = new Node(vec[idx]) ;
    root->left = buildTree(vec) ;
    root->right = buildTree(vec) ;
    return root ;
}

bool helper(Node* root , Node* min , Node* max){
    if(root == NULL) return true ;

    if(min != NULL && root->data <= min->data){
        return false ;
    }
    if(max != NULL && root->data >= max->data){
        return false ;
    }

    return helper(root->left , min , root) && helper(root->right , root , max) ;
}

bool validBST(Node* root){
    return helper(root, NULL , NULL) ;
}

int main(){
    vector<int> vec = {5,1,-1,-1,4,3,-1,-1,6,-1,-1} ;
    Node* root = buildTree(vec) ;
    
    cout << "Is valid BST : " << validBST(root) << endl ;
}