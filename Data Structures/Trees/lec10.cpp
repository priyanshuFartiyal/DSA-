// Binary Tree Paths (Leetcode -> 257)

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

Node* buildTree(vector<int> vec , int &idx){
    idx++ ;
    if(vec[idx] == -1) return NULL ;
    Node* root = new Node(vec[idx]) ;
    root->left = buildTree(vec , idx) ;
    root->right = buildTree(vec , idx) ;
    return root ;
}

void allPaths(Node* root , vector<string> &ans , string path){
    if(root->left == NULL && root->right == NULL){
        ans.push_back(path) ;
        return ;
    }

    if(root->left){
        allPaths(root->left , ans , path+"->"+to_string(root->left->data) ) ;
    }
    if(root->right){
        allPaths(root->right , ans , path+"->"+to_string(root->right->data) ) ;
    }

}

int main(){
    vector<int> vec = {1,2,-1,-1,3,4,-1,-1,5 ,-1,-1} ;
    int idx = -1 ;
    Node* root = buildTree(vec , idx) ;
    vector<string> ans ;
    string path = to_string(root->data) ; // atleast one node is their(given)
    allPaths(root , ans , path) ;
    for(auto val : ans){
        cout << val << endl ;
    }
}