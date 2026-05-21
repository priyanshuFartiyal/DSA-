// Flatten the Binary Tree (Leetcode ->114)

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

Node* nextRight = NULL ;
void flattenTree(Node* root){

    if(root == NULL) return ;
    flattenTree(root->right) ;
    flattenTree(root->left) ;

    root->left = NULL ;
    root->right = nextRight ;
    nextRight = root ;
}

int main(){
    vector<int> vec = {1,2,3,-1,-1,4,-1,-1,5,6,-1,-1,7,-1,-1} ;
    Node* root = buildTree(vec) ;
    flattenTree(root) ;

    Node* temp = root ;
    while(temp != NULL){
        cout << temp->data << "->" ;
        temp = temp->right ;
    }
    cout << "NULL" << endl ;
}