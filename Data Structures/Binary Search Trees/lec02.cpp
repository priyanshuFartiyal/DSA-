// Making balanced BST from Sorted Array ( Leetcode ->108 )

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

Node* helper(vector<int> vec , int st , int end){
    if(st > end) return NULL ;
    int mid = st + (end-st)/2 ;
    Node* root = new Node(vec[mid]) ;
    root->left = helper(vec , st , mid-1) ;
    root->right = helper(vec , mid+1 , end);
    return root ;
}

Node* buildBST(vector<int> vec){
    return helper(vec , 0 , vec.size()-1) ;
}

int main(){
    vector<int> vec = {-10,-3,0,2,4} ;
    Node* root = buildBST(vec) ;
}