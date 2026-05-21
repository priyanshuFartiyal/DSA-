// Construct BST from preorder ( Leetcode -> 1008 )

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

Node* helper(vector<int> &preorder , int &i , int bound){

    if(i >= preorder.size() || preorder[i] > bound) return NULL ;
    Node* root = new Node(preorder[i]) ;
    i++ ;
    root->left = helper(preorder , i , root->data) ;
    root->right = helper(preorder , i , bound) ;
    return root ;
}

Node* buildBST(vector<int> &preorder){
    int i = 0 ;
    return helper(preorder , i , INT_MAX) ;
}

int main(){
    vector<int> vec = {6,3,1,4,8,9} ;
    Node* root = buildBST(vec) ;
    cout << root->data << endl ;
}