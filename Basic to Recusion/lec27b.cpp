// Search in 2-D Matrix (II) (Leetcode Q.240)

#include<iostream>
#include<vector>
using namespace std ;

// search in top right corner 
bool searchElement(vector<vector<int>> mat , int target){
    int m = mat.size() ;
    int n = mat[0].size() ;
    int row = 0 , col = n-1 ;
    while(row <= m-1 && col >= 0){
        if(target == mat[row][col]){
            return true ;
        }
        else if(target < mat[row][col]){
            col -- ;
        }
        else{
            row ++ ;
        }
    }
    return false ;
}

// // or you can either search from bottom left corner 
// bool searchElement(vector<vector<int>> mat , int target){
//     int m = mat.size() ;
//     int n = mat[0].size() ;
//     int row = m-1 , col = 0 ;
//     while(row >= 0 && col <= n-1){
//         if(target == mat[row][col]){
//             return true ;
//         }else if(target < mat[row][col]){
//             row--;
//         }else{
//             col++;
//     }
//     }
//     return false ;
// }

int main(){
    vector<vector<int>> vec = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}} ;
    int target = 5 ;
    cout << "Target exist -> " << searchElement(vec,target) <<endl ;
}