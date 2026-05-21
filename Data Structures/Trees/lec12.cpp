// Morris Inorder Traversal (Algorithm)

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
    if(vec[idx] == -1) return NULL ;
    Node* root = new Node(vec[idx]) ;
    root->left = buildTree(vec) ;
    root->right = buildTree(vec) ;
    return root ;
}

/* // Recusrive Approach
void inOrder(Node* root){
    if(root == NULL) return ;
    inOrder(root->left) ;
    cout << root->data << " " ;
    inOrder(root->right) ;
    return ;
} */

void MorrisInOrder(Node* root){
    Node* curr = root ;
    while(curr != NULL){
        if(curr->left == NULL){
            cout << curr->data << " " ;
            curr = curr->right ;
        }else{
            Node* IP = curr->left ;
            while(IP->right != NULL && IP->right != curr){
                IP = IP->right ;
            }

            if(IP->right == NULL){
                IP->right = curr ;
                curr = curr->left ;
            }else{
                IP->right = NULL ;
                cout << curr->data << " " ;
                curr = curr->right ;
            }
        }
    }
    return ;
}

int main(){
    vector<int> vec = {1,2,3,-1,-1,4,-1,-1,5,6,-1,-1,7,-1,-1} ;
    Node* root = buildTree(vec) ;
    MorrisInOrder(root) ;

}