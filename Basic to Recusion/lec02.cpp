// Vector 

#include<iostream>
#include <vector>
using namespace std ;

int main()
{
    // // Syntax of Vector 


    // vector <int> vec ;
    // cout << vec[0] << endl ; // segmentation error 
    // vector <int> vec = {1,2,3,4,5} ;
    // cout << vec[0] << endl ;

    // vector<int> vec(5 , 0) ; // vector of size 5 and initiate with value 0 
    // /*
    // cout << vec[0] << endl ;
    // cout << vec[1] << endl ;
    // cout << vec[2] << endl ;
    // cout << vec[3] << endl ;
    // cout << vec[4] << endl ;
    // */
    // // Use "for each loop" instead 
    // for(int i : vec)
    // {
    //     cout << i << " " ;
    // }

    // // Function in Vector
    // vector <int> vec = {11 ,12  , 13 , 14, 15} ;
    // // Size()
    // cout << "Size = " << vec.size() << endl ;
    // for(int i : vec)
    // {
    //     cout << i << " " ;
    // }cout << endl ;
    // // push_back()
    // vec.push_back(43) ;
    // cout << "Size = " << vec.size() << endl ;
    // // pop_back()
    // vec.pop_back() ;
    // cout << "Size = " << vec.size() << endl ;
    // // front() & back()
    // cout << vec.front() << endl ;
    // cout << vec.back() << endl ;
    // // at()
    // cout << "element at index 3 = " << vec.at(3) << endl ; 

    // // Size vs Capacity 
    // cout << "size = " << vec.size() << endl; 
    // cout << "capacity = " <<vec.capacity() << endl ;


    // Single Number Problem with array 
    // You can do this with n^2 complexity but the task is to do it with linear complexity
    int arr[] = {1 ,1 ,4 , 2 ,2} ;
    int size = 5 ;

    int value = arr[0];
    for(int i = 0 ; i < size-1 ; i++){
        value ^= arr[i+1] ;
    }
    
    cout << "The unique value by array is " << value << endl ;


    // Single Number problem with vector 
    vector<int> vec = {1 ,1 ,4 , 2 ,2} ;
    int ans = 0 ;
    for(int val : vec) {
        ans ^= val ;
    }
    cout << "The unique value by vector is " << ans << endl ;

    
}