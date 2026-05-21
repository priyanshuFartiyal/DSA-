// Product of Array except Self ( Leetcode -> Q.238 )

#include<iostream>
#include<vector>
using namespace std ;

int main()
{

    int arr[] = {1,2,3,4} ;
    int size = sizeof(arr)/sizeof(int) ;
    vector<int> vec(size , 1);
    
    // // Brute Force Approach ( n*n )
    // for(int i = 0 ; i < size ; i++){
    //     int product = 1 ;
    //     for(int j = 0 ; j < size ; j++){
    //         if(i!=j){
    //             product *= arr[j] ;
    //         }
    //     }
    //     vec[i] = product ;
    // }

    // for(int val : vec){
    //     cout << val << " " ;
    // }


    // // Optimum Way -> O(n) 
    // vector<int> prefix(size , 1) ;
    // vector<int> suffix(size , 1) ;
    // for(int i = 1 ; i < size ; i++){
    //     prefix[i] = prefix[i-1] * arr[i-1] ;
    // }
    // for(int i = size-2 ; i >= 0 ; i--){
    //     suffix[i] = suffix[i+1] * arr[i+1] ;
    // }
    // for(int i = 0 ; i < size ; i++){
    //     vec[i] = prefix[i] * suffix[i] ;
    // }

    // for(int val : vec){
    //     cout << val << " " ;
    // }


    // Upper solution is good but spaceComplexity -> O(n) -> needs to be decreased 
    // to O(1) as per question in Leetcode .. so we can use only 1 container 

    int prefix = 1 ;
    for(int i = 0 ; i < size ; i++){
        vec[i] = prefix ;
        prefix *= arr[i] ;
    }
    int suffix = 1 ;
    for(int i = size-1 ; i >= 0 ; i--){
        vec[i] *= suffix ;
        suffix *= arr[i] ;
    }
    for(int val : vec){
        cout << val << " ";
    }
    
}