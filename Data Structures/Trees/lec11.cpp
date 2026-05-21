// Maximum Width of Binary Tree (Leetcode -> 662)

#include<iostream>
#include<vector>
#include<deque>
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
    idx ++ ;
    if(vec[idx] == -1) return NULL ;
    Node* root = new Node(vec[idx]) ;
    root->left = buildTree(vec) ;
    root->right = buildTree(vec) ;
    return root ;
}

int maxWidthTree(Node* root){
    deque<pair<Node* , int>> q ;
    q.push_front({root , 0}) ;
    unsigned long long maxWidth = 0 ;
    while(!q.empty()){
        int currLevelSize = q.size() ;
        unsigned long long leftIdx = q.front().second ;
        unsigned long long rightIdx = q.back().second ;
        maxWidth = max(maxWidth , rightIdx-leftIdx+1) ;
        for(int i = 0 ; i < currLevelSize ; i++){
            auto curr = q.front() ;
            q.pop_front() ;
            if(curr.first->left){
                q.push_back({curr.first->left , curr.second*2+1}) ;
            }
            if(curr.first->right){
                q.push_back({curr.first->right , curr.second*2+2}) ;
            }
        }
    }
    return maxWidth ;

}

int main(){
    vector<int> vec = {1,2,3,-1,-1,4,-1,-1,5,6,-1,-1,-1 } ;
    Node* root = buildTree(vec) ;
    int maxi = maxWidthTree(root) ;
    cout << maxi << endl ;
}