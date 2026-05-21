// Identical Tree (Leetcode -> 100) & SubTree of Another Tree (Leetcode -> 572)

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
Node* buildTree(vector<int> vec , int &idx){
    idx++ ;
    if(vec[idx] == -1) return NULL ;
    Node* root = new Node(vec[idx]) ;
    root->left = buildTree(vec , idx) ;
    root->right = buildTree(vec , idx) ;
    return root ;
}

bool isIdentical(Node* p , Node* q){
    if(p==NULL || q==NULL) return p==q ;
    return p->data == q->data && isIdentical(p->left , q->left) && isIdentical(p->right , q->right) ;
}


bool isSubtree(Node* root , Node* subRoot){
    if(root == NULL || subRoot == NULL) return root==subRoot ;
    if(root->data == subRoot->data && isIdentical(root , subRoot)){
        return true ;
    }
    return isSubtree(root->left , subRoot) || isSubtree(root->right , subRoot) ;
}

int main(){
    vector<int> vec1 = {1,2,-1,-1,3,4,-1,-1,5,-1,-1} ;
    int idx1 = -1 ;
    Node* root1 = buildTree(vec1 , idx1) ;
    vector<int> vec2 = {3,4,-1,-1,5,-1,-1} ;
    int idx2 = -1 ;
    Node* root2 = buildTree(vec2 , idx2) ;
    cout << "Is SUbtree = " << isSubtree(root1 , root2)  << endl ;
}
