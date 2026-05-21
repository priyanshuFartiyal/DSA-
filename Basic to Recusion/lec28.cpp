// Spiral Matrix (Leetcode -> Q.54)

#include<iostream>
#include<vector>
using namespace std ;

vector<int> printSpiral(vector<vector<int>> mat ){
    vector<int> ans ;
    int m = mat.size() ;
    int n = mat[0].size() ;
    int srow = 0 , erow = m-1 , scol = 0 , ecol = n-1 ;
    while(srow <= erow && scol <= ecol){
        for(int j = scol ; j <= ecol ; j++){
            ans.push_back(mat[srow][j]) ;
        }
        for(int i = srow+1 ; i<= erow ; i++){
            ans.push_back(mat[i][ecol]) ;
        }
        for(int j = ecol-1 ; j >= scol ; j--){
            if(srow == erow){
                break ;
            }
            ans.push_back(mat[erow][j]) ;
        }
        for(int i = erow-1 ; i >= srow+1 ; i--){
            if(scol == ecol){
                break ;
            }
            ans.push_back(mat[i][scol]) ;
        }
        srow++ , scol++ , erow-- , ecol-- ;
    }
    return ans ;
}

int main(){
    vector<vector<int>> vec = {{1,2,3},{4,5,6},{7,8,9}} ;
    vector<int> ans = printSpiral(vec) ;
    for(int val : ans){
        cout << val << " " ;
    }
}