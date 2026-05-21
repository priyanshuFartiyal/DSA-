// Merge Two Binary Search Tree (Leetcode ->  )

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node{
    public:
    int data ;
    Node* left ;
    Node* right ;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

static int idx = -1; 
Node* buildTree(vector<int> vec){
    idx++ ;
    if(vec[idx] == -1) return NULL ;
    Node* root = new Node(vec[idx]) ;
    root->left = buildTree(vec) ;
    root->right = buildTree(vec) ;
    return root ;
}


void inorder(Node* root , vector<int> &vec){
    if(root == NULL) return ;
    inorder(root->left , vec) ;
    int val = root->data ;
    cout << "Val pushed = " << val << endl ;
    vec.push_back(val) ;
    inorder(root->right , vec) ;
    return ;
}



int main(){
    vector<int> tree1 = {8,2,1,-1,-1,-1,10,-1,-1} ;
    vector<int> tree2 = {5,3,8,-1,-1,-1,-1} ;

    Node* root1 = buildTree(tree1) ;
    Node* root2 = buildTree(tree2) ;
    
    vector<int> vec ;
    inorder(root1 , vec) ;
    inorder(root2 , vec) ;

    sort(vec.begin() , vec.end()) ;

    for(int val : vec){
        cout << val << " " ;
    }cout << endl ;

}