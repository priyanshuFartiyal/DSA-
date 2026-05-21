// Top view of Binary Tree 

/*
To get top view do levelWise travelsal and while moving on each node
assign the horizontal distance to each node so that atlast when checked 
the nodes with same horizontal can be ignored as they fall under some other node
*/

#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

void topView(Node* root){
    queue<pair<Node* , int>> q ;
    map<int, int> m ;

    q.push({root , 0}) ;

    while(!q.empty()){
        Node* curr = q.front().first ;
        int currHD = q.front().second ;
        q.pop() ;

        if(m.find(currHD) == m.end()){
            m[currHD] = curr->data ;
        }//else{
        //     m[currHD] = curr->data ; // This additional line of code can turn the view from top to bottom
        // }

        if(curr->left != NULL){
            q.push({curr->left , currHD-1 } ) ;
        }
        if(curr->right != NULL){
            q.push({curr->right , currHD+1}) ;
        }
    }

    for(auto it : m){
        cout << it.second << " " ;
    }cout << endl ;
}

int main(){
    vector<int> vec = {1,2,-1,-1,3,4,-1,-1,5,-1,-1} ;
    Node* root = buildTree(vec) ;
    topView(root) ;
}