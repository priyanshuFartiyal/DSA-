// Max Subarray Problem (Leetcode -> Q.53)
#include<iostream>
#include<vector>
#include<climits>
using namespace std ;

int main()
{
    int arr[] = {3, -4, 5, 4, -1, 7, -8} ;
    int size = 7 ;
    // // for acessing all the possible subarrays 
    // for(int i = 0 ; i< size ; i++){
    //     for(int j = i ; j < size ; j++){
    //         for(int k = i ; k < j ; k++){
    //             cout << arr[k] ;
    //         }cout << " " ;
    //     }cout << endl ;
    // }

    // // for finding maximum Sum of elements of any possible Subarray

    // // Brute Force Approach ( n*n )
    // int maxSum = INT_MIN ;
    // for(int i = 0 ; i < size ; i++){
    //     int currSum = 0 ;
    //     for(int j = i ; j < size ; j++){
    //         currSum += arr[j] ;
    //         maxSum = max(currSum , maxSum) ;
    //     }
    // }
    // cout << "Max sum is : " << maxSum << endl ;

    // Kadane's Algorithm (linear Order Complexity)
    int currentSum = 0 , maxSum = INT_MIN ;
    for(int i = 0 ; i < size ; i++){
        currentSum += arr[i] ;
        maxSum = max(currentSum , maxSum) ;
        if(currentSum < 0 ){
            currentSum = 0 ;
        }
    }
    cout << "Max sum is : " << maxSum << endl ;


}

