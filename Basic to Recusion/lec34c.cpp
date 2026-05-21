// Binary Recursive Call (Leetcode -> Q.704)

#include<iostream>
using namespace std ;

binSearch(int arr[] , int target ,int st , int end){

        if(st > end){
            return -1 ;
        }

        int mid = st + (end-st)/2 ;
        if(arr[mid] == target){
            return mid ;
        }else if(arr[mid] < target){
            binSearch(arr , target , mid+1 , end) ;
        }else{
            binSearch(arr, target , st , mid-1) ;
        }


}

int main(){
    int arr[5] = {1,3,5,7,8} ;
    int size = sizeof(arr)/sizeof(arr[0]) ;
    int st = 0 , end = size-1 ;
    int target = 56 ;
    int ans = binSearch(arr,target,st , end) ;
    cout << "Element is at index " << ans << endl ;
}