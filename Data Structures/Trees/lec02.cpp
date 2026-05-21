// Calculating height of a tree , count of Nodes and Sum of data of Nodes 

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
Node* binaryTree(vector<int> vec){
    idx ++ ;
    if(vec[idx] == -1){
        return NULL ;
    }
    
    Node* root = new Node(vec[idx]) ;
    root->left = binaryTree(vec) ;
    root->right = binaryTree(vec) ;
    return root;
}

// Height of a Tree 
int height(Node* root){

    if(root == NULL){
        return 0 ;
    }
    int lfht = height(root->left) ;
    int rght = height(root->right) ;
    return max(lfht , rght) + 1 ;
}

// Count of Nodes 
int count(Node *root){
    if(root == NULL){
        return 0 ;
    }
    int lfct = count(root->left) ;
    int rgct = count(root->right) ;
    return lfct + rgct + 1 ;
}

// Sum of Data of Nodes
int Sum(Node *root){
    if(root == NULL){
        return 0 ;
    }

    int lfsum = Sum(root->left) ;
    int rgsum = Sum(root->right) ;
    return lfsum + rgsum + root->data ;
}

int main(){
    vector<int> vec = {1,2,-1,-1,3,4,-1,-1,5,-1,-1} ;
    Node *root =binaryTree(vec) ;
    int ht = height(root) ;
    cout << "Height of Tree = " << ht << endl ;
    int ct = count(root) ;
    cout << "No. of nodes = " << ct << endl ;
    int sum = Sum(root) ;
    cout << "Sum of data of all Nodes = " << sum << endl ;
}