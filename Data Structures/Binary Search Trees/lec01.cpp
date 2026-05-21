// Building Binary Search Trees , search & deletion on BST

// Need -> Traversal Time = O(heightt) = O(log n) becoz we take balanced tree
// here inorder sequence is sorted sequence 

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

// Building BST
Node* insert(Node* root , int val){
    if(root == NULL) return new Node(val) ;
    
    if(val < root->data){
        root->left = insert(root->left , val) ;
    }else{
        root->right = insert(root->right , val) ;
    }
    return root ;
}

Node* buildBST(vector<int> vec){
    Node* root = NULL ;
    for(int val : vec){
        root = insert(root , val) ;
    }
    return root ;
}

// Print BST inorder sequence
void inOrder(Node* root){
    if(root == NULL) return ;
    inOrder(root->left) ;
    cout << root->data << " ";
    inOrder(root->right) ;
}

// O(height of tree) -> if tree is balanced = O(log n)
bool search(Node* root , int val){
    if(root == NULL){
        return false ;
    }
    if(val == root->data) return true ;
    if(val < root->data){
        return search(root->left , val) ;
    }else{
        return search(root->right , val) ;
    }
}

// Deleting a Node in BST
Node* getInorderSuccessor(Node *root){ // leftmost node in the right subtree
    while(root != NULL && root->left != NULL){
        root = root->left ;
    }
    return root ;
}

Node* deletion(Node* root , int val){
    if(root == NULL) return NULL ;

    if(val < root->data){
        root->left = deletion(root->left , val) ;
    }else if(val > root->data){
        root->right = deletion(root->right , val) ;
    }else{
        // root->data = val 
        // for 1 or 0 child
        if(root->left == NULL){
            Node* temp = root->right ;
            delete root ;
            return temp ;
        }else if(root->right == NULL){
            Node* temp = root->left ;
            delete root ;
            return temp ;
        }// for 2 child 
        else{
            Node* IS = getInorderSuccessor(root->right) ;
            root->data = IS->data ;
            deletion(root->right , IS->data) ;
            
        }   
    }
    return root ;
}

int main(){

    vector<int> vec = {3,2,1,5,6,4} ;

    // Build BST 

    Node* root = buildBST(vec) ;
    // To check if the BST is sucessfully set
    inOrder(root) ; 
    cout << endl ;


    // Search 

    cout << "Exist : " << search(root , 3) << endl ;

    
    // Deletion Operation

    cout << "Before deletion : " ;
    inOrder(root) ; cout << endl ;

    deletion(root ,3) ;

    cout << "After deletion  : " ;
    inOrder(root) ;cout << endl ;
    
}