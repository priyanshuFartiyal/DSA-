// Diagonal Sum of a Matrix

#include<iostream>
#include<vector>
using namespace std ;

int diagonalSum(int mat[][4] , int n){
    int sum = 0;
    for(int i = 0 ; i < n ; i++ ){
        // for(int j = 0 ; j < n ; j++){
        //     if(j==i){
        //         sum += mat[i][j] ;
        //     }else if(j+i == n-1 ){
        //         sum += mat[i][j] ;
        //     }
        // }

        // Instead of nested loop we can do this in O(n) time complexity
        sum += mat[i][i] ;
        if(i != n-i-1){
            sum += mat[i][n-i-1] ;
        }
    }
    return sum ;
}

int main(){

    int matrix[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}} ;
    int n = 4 ;
    int ans = diagonalSum(matrix , n) ;
    cout << "Diagonal sum = " << ans << endl ;


    // 2-D vector
    vector<vector<int>> vec = {{1,2,3},{4,5,6},{7,8,9}} ;
    int rows = vec.size() ;
    int cols = vec[0].size() ;
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cols ; j++){
            cout << vec[i][j] << " " ;
        }cout << endl ;
    }
    
    /* 
        NOTE : We can have non-matrix form storage in 2-D vector 
            1 2 3
            4 5 6 7 8 
            9 3 4
    */
}
