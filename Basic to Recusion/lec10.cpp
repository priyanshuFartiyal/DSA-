// Search in Rotated Sorted Array (Leetcode -> Q.33)

/* 
The array was initially sorted then rotated by some indices now we need to find 
    any particular element in "Rotated Sorted Array" .
We can do it by linear Search but we prefer to do it with (modified Binary Search)
    i.e complexity -> O(log n)
*/ 

#include<iostream>
#include<vector>
using namespace std ;

int BinSearch(vector<int> vec , int target){
    int st = 0 , end = vec.size()-1 ;
    while(st < end){
        int mid = st + (end-st)/2 ;
        if(vec[mid] == target){
            return mid ;
        }
        if(vec[st] <= vec[mid]){ // i.e Left side Sorted
            if(vec[st] <= target && target < vec[mid]){
                end = mid-1 ;
            }else{
                st = mid+1 ;
            }
        }else{ // If Right side sorted
            if(vec[mid] <= target  && target <= vec[end]){
                st = mid+1 ;
            }else{
                end = mid-1 ;
            }
        }
    }
    return -1;
    
}

int main(){
    vector<int> vec = {6 ,7 ,8 ,0 ,1 ,2 ,3 ,4 ,5} ;
    int target = 3 ;
    int ans = BinSearch(vec , target) ;
    ans == -1 ? cout << "No element Found !!" : cout << "Element found at index : " << ans ;
}