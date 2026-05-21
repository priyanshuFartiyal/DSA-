// Kth smallest in BST ( Leetcode -> 230 )

#include<iostream>
#include<vector>
#include<climits>
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

int kthSmallest(Node* root , int k , int &count){
    if(root == NULL) return -1 ;

    int leftMin = kthSmallest(root->left , k , count) ;
    if(leftMin != -1) return leftMin ;

    count++ ;
    if(count == k) return root->data ;

    int rightMin = kthSmallest(root->right , k , count) ;
    if(rightMin != -1) return rightMin ;
    
    return -1 ;
}

int main(){
    vector<int> vec = {5,3,2,1,-1,-1,-1,4,-1,-1,6,-1,-1} ;
    Node* root = buildTree(vec) ;
    int k = 3 ;
    int count = 0 ;
    int smallest = kthSmallest(root , k , count) ;
    cout << smallest << endl ;
}