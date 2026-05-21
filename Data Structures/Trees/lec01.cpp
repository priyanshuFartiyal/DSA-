// Building a Tree and Traversal - PreOrder , PostOrder , InOrder , Levelwise

#include<iostream>
#include<vector>
#include<queue>
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

    if(vec[idx] == -1) {
        return NULL ;
    }

    Node* root = new Node(vec[idx]) ;
    root->left = buildTree(vec) ; // LEFT Subtree 
    root->right = buildTree(vec) ; // RIGHT Subtree

    return root ;
}

void PreOrderTraverse(Node *root){
    if(root == NULL){
        return ;
    }
    cout << root->data << " ";
    PreOrderTraverse(root->left) ;
    PreOrderTraverse(root->right) ;

}

void InOrderTraverse(Node *root){
    if(root == NULL){
        return ;
    }
    InOrderTraverse(root->left) ;
    cout << root->data << " ";
    InOrderTraverse(root->right) ;

}

void PostOrderTraverse(Node *root){
    if(root == NULL){
        return ;
    }
    PostOrderTraverse(root->left) ;
    PostOrderTraverse(root->right) ;
    cout << root->data << " ";

}

void LevelTraverse(Node* root){
    queue<Node*> q ;
    q.push(root) ;
    q.push(NULL) ;

    while(!q.empty()){
        Node* curr = q.front() ;
        q.pop() ;

        if(curr == NULL){
            if(!q.empty()){
                cout << endl ;
                q.push(NULL) ;
                continue ;
            }else{
                break ;
            }
        }

        cout << curr->data << " " ;
        
        if(curr->left != NULL){
            q.push(curr->left) ;
        }
        if(curr->right != NULL){
            q.push(curr->right) ;
        }
    }
}

int main(){
    vector<int> vec = {1,2,-1,-1,3,4,-1,-1,5,-1,-1} ;
    Node* root = buildTree(vec) ;
    PreOrderTraverse(root) ;
    cout << endl ;
    InOrderTraverse(root) ;
    cout << endl ;
    PostOrderTraverse(root) ;
    cout << endl ;
    LevelTraverse(root) ;
    cout << endl ;
}
