// Rat in a Maze 

#include<iostream>
#include<vector>
#include<string>
using namespace std ;

void getPath(vector<vector<int>> &mat , int r , int c ,vector<string> &ans , string path , vector<vector<bool>> &vis){
    int n = mat.size() ;

    if(r<0 || c<0 || r>=n || c>=n || mat[r][c] == 0 || vis[r][c] == true ){
        return ;
    }

    if(r == n-1 && c == n-1){
        ans.push_back(path) ;
        return ;
    }

    vis[r][c] = true ;
    getPath(mat , r+1 , c , ans , path+"D" , vis) ; // Down
    getPath(mat , r , c+1 , ans , path+"R" , vis) ; // Right
    getPath(mat , r , c-1 , ans , path+"L" , vis) ; // Left 
    getPath(mat , r-1 , c , ans , path+"U" , vis) ; // Up
    vis[r][c] = false ;
    
}

vector<string> findPath(vector<vector<int>> &mat){
    int n = mat.size() ;
    vector<vector<bool>> vis(n , vector<bool>(n, false)) ;
    vector<string> ans ;
    string path = "" ;
    getPath(mat , 0 , 0 , ans , path , vis) ;
    return ans ;
}

int main(){
    vector<vector<int>> mat = {{1,0,0,0} , {1,1,0,1} , {1,1,0,0} , {0,1,1,1}} ;
    vector<string> ans = findPath(mat) ;
    for(string path : ans){
        cout << path << endl ;
    }
    return 0 ;
}
