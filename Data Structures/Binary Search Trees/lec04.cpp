// Min difference between BST ( Leetcode -> 783 )

#include<iostream>
#include<vector>
#include<climits>
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

static int idx = -1 ;
Node* buildTree(vector<int> vec){
    idx++ ;
    if(vec[idx] == -1) return NULL ;
    Node* root = new Node(vec[idx]) ;
    root->left = buildTree(vec) ;
    root->right = buildTree(vec) ;
    return root ;
}

void inorder(Node* root){
    if(root == NULL ) return ;
    inorder(root->left) ;
    cout << root->data  << " ";
    inorder(root->right) ;
}

// Min difference function by help of inorder traversing 

Node* prevNode = NULL ;
int ans = INT_MAX ;

void minDiff(Node* root){
    if(root == NULL) return ;
    minDiff(root->left) ;
    if(prevNode){
        ans = min(ans , root->data - prevNode->data) ;
    }
    prevNode = root ; 
    minDiff(root->right) ;
}
        
int main(){
    vector<int> vec = {83,62,42,-1,52,-1,-1,82,-1,-1,88,-1,-1} ;
    Node* root = buildTree(vec) ;
    inorder(root) ; cout << endl ;

    minDiff(root) ;
    cout << "Min Difference btween node : " << ans ;
}