// Container With Most Water (Leetcode -> Q.11)

#include<iostream>
using namespace std ;

int main(){

    // // Brute Force Approach -> O(n*n)

    // int arr[] = {1,8,6,2,5,4,8,3,7} ;
    // int size = sizeof(arr)/sizeof(int) ;
    // int maxWater = 0 ;
    // for(int i = 0 ; i < size-1 ; i++){
    //     int length , height , water ;
    //     for(int j = i+1 ; j < size ; j++){
    //         length = j - i ; 
    //         height = min(arr[i] , arr[j]) ;
    //         water = length * height ;
    //         maxWater = max(maxWater , water) ;
    //     }
    // }
    // cout << "Maximum water that can be stored is : " << maxWater << endl ;

    // But in Leetcode the upper code will give TLE (Time limit exceeds) 
    // Thus we use two pointer approach -> O(n)

    int arr[] = {8,7,2,1} ;
    int size = sizeof(arr)/sizeof(arr[0]) ;
    int st = 0 , end = size-1 , max_water = 0 ;
    while(st < end){
        int length = end - st ;
        int height = min(arr[st] , arr[end]) ;
        int water = length * height ;
        max_water = max(water , max_water) ;

        arr[st] < arr[end] ? st++ : end-- ;
    }
    cout << "Max water that can be stored is : " << max_water << endl ;
}