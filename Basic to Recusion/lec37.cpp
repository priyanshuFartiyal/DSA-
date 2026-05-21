// N Queens Problem (Leetcode -> Q.51)

#include<iostream>
#include<vector>
#include<string>
using namespace std ;

bool isSafe(vector<string> &board , int row , int col , int n){
    //Horizontal Checking 
    for(int j = 0 ; j < n ; j++){
        if(board[row][j] == 'Q'){
            return false ;
        }
    }

    //Vertical Checking 
    for(int i = 0 ; i < n ; i++){
        if(board[i][col] == 'Q'){
            return false ;
        }
    }

    // Diagonal Checking (left)
    for(int i=row , j=col ; i >= 0 && j >= 0 ; i-- , j--){
        if(board[i][j] == 'Q'){
            return false ;
        }
    }

    //Diagonal Checking (right)
    for(int i=row , j=col ; i>=0 && j<n ; i-- , j++){
        if(board[i][j] == 'Q'){
            return false ;
        }
    }

    // Safe Position 
    return true ;
}

void nQueens(vector<string> &board , int row , int n , vector<vector<string>> &ans){
    if(row == n){
        ans.push_back(board) ;
        return ;
    }

    for(int j = 0 ; j < n ; j++){
        if(isSafe(board , row , j , n)){
            board[row][j] = 'Q' ;
            nQueens(board , row+1 , n , ans) ;
            // Backtracking i.e reallocation of queen in another position.
            board[row][j] = '.' ;
        }
    }
   
}

int main(){
    int n = 4 ;
    vector<string> board(n , string(n,'.')) ;
    vector<vector<string>> ans ;
    nQueens(board , 0 , n , ans) ;

    for(auto val : ans){
        for(auto x : val){
            cout << x << endl ;
        }cout << endl ;
    }
}

