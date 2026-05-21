// Sudoku Solver (Leetcode -> Q.37)

#include<iostream>
#include<vector>
using namespace std ;

bool isSafe(vector<vector<char>> &board , int row , int col , int dig){
    // Horizontal Checking 
    for(int j = 0 ; j < 9 ; j++){
        if(board[row][j] == dig){
            return false ;
        }
    }
    // Vertical Checking 
    for(int i = 0 ; i < 9 ; i++){
        if(board[i][col] == dig){
            return false ;
        }
    }
    // Grid Checking (3*3 grid size)
    int stRow = (row/3)*3 ;
    int stCol = (col/3)*3 ;
    for(int i = stRow ; i <= stRow+2 ; i++){
        for(int j = stCol ; j <= stCol+2 ; j++){
            if(board[i][j] == dig){
                return false ;
            }
        }
    }

    // Safe to place dig
    return true ;
}

bool sudoku(vector<vector<char>> &board , int row , int col){
    // Base Case 
    if(row == 9){
        return true ;
    }

    int nxRow = row ;
    int nxCol = col+1 ;
    if(nxCol == 9){
        nxRow = row+1 ;
        nxCol = 0 ;
    }

    if(board[row][col] != '.'){
        return sudoku(board , nxRow , nxCol) ;
    }

    for(char dig = '1' ; dig <= '9' ; dig++){
        if(isSafe(board , row , col ,dig)){
            board[row][col] = dig ;
            if(sudoku(board , nxRow , nxCol)){
                return true ;
            }
            board[row][col] = '.' ;
        }
    }

    return false ;
}

int main(){
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
{'6','.','.','1','9','5','.','.','.'},
{'.','9','8','.','.','.','.','6','.'},
{'8','.','.','.','6','.','.','.','3'},
{'4','.','.','8','.','3','.','.','1'},
{'7','.','.','.','2','.','.','.','6'},
{'.','6','.','.','.','.','2','8','.'},
{'.','.','.','4','1','9','.','.','5'},
{'.','.','.','.','8','.','.','7','9'}
} ;
    sudoku(board , 0 , 0) ;
    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ;  j < 9 ; j++){
            cout << board[i][j] << " ";
        }cout << endl ;
    }
}