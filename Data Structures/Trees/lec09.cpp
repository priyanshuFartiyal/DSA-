// Transforming a tree to Sum Tree 

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

static int idx = -1;
Node* buildTree(vector<int> vec){
    idx ++ ;
    if(vec[idx] == -1) return NULL ;
    Node* root = new Node(vec[idx]) ;
    root->left = buildTree(vec) ;
    root->right = buildTree(vec) ;
    return root ;
}

Node* transformTree(Node*root){
    if(root == NULL) return NULL ;
    Node* leftSum = transformTree(root->left) ;
    Node* rightSum = transformTree(root->right) ;
    if(leftSum && rightSum){
        root->data = (leftSum->data + rightSum->data + root->data) ;
        return root ;
    }
    else if(leftSum != NULL){
        root->data = leftSum->data + root->data ;
        return root ;
    }else if(rightSum != NULL){
        root->data = rightSum->data + root->data ;
    }else{
        return root ;
    }
}

int main(){
    vector<int> vec = {1,2,-1,-1,3,4,-1,-1,5,-1,-1} ;
    Node* root = buildTree(vec) ;
    Node* newRoot = transformTree(root) ;

}