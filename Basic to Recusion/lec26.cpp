// 2-D Arrays (Basic Operations)

#include<iostream>
using namespace std ;

int main()
{
    int rows = 4 ;
    int columns = 3 ;
    // int matrix[rows][columns] = {{1,2,3} , {4,5,6} , {7,8,9} , {10,11,12}} ;
    // cout << matrix[1][2] << endl ; // single element excess.
    int matrix[rows][columns] ; 
    // Taking elements of 2-D array 
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < columns ; j++){
            cin >> matrix[i][j] ;
        }
    }
    // Printing all elements by looping .
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < columns ; j++){
            cout << matrix[i][j] << " " ;
        }
        cout << endl ;
    }
    
}