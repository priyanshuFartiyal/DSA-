// Diameter of a tree (Leetcode -> 543)

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

static int idx = -1 ;
Node* buildTree(vector<int> vec){
    idx++ ;
    if(vec[idx] == -1){
        return NULL ;
    }
    Node* root = new Node(vec[idx]) ;
    root->left = buildTree(vec) ;
    root->right = buildTree(vec) ;
    return root ;
}

/* // O(n*n) 
int height(Node* root){
    if(root == NULL) return 0 ;
    int lfht = height(root->left) ;
    int rght = height(root->right) ;
    return max(lfht , rght) + 1 ;
}

int diameter(Node* root){
    if(root == NULL) return 0 ;
    int lfDia = diameter(root->left) ;
    int rgDia = diameter(root->right) ;
    int currDia = height(root->left) + height(root->right) ;
    return max(max(lfDia , rgDia) , currDia) ;
} */

// O(n)
int ans = 0 ;
int height(Node* root){
    if(root == NULL) return 0 ;
    int lfht = height(root->left) ;
    int rght = height(root->right) ;
    ans = max(ans , lfht + rght) ;
    
    return max(lfht , rght) + 1 ;
}
int diameter(Node* root){
    height(root) ;
    return ans ;
}


int main(){
    vector<int> vec = {1,2,-1,-1,3,4,-1,-1,5,-1,-1} ;
    Node* root = buildTree(vec) ;
    
    cout << "Max DIameter = " << diameter(root) << endl ;
}