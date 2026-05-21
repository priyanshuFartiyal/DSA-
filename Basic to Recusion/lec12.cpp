// Single Element in Sorted Array (Leetcode -> Q.540)

#include<iostream>
#include<vector>
using namespace std ;

// We can check which is the only single element in array just by
// Linear search but we have to do it in O(log n) so we do binary search

int SingleElement(vector<int> vec ){
    int size = vec.size() ;
    int st = 0  , end = size-1 ;

    // what if vector contains only 1 element
    if(size == 1){
        return vec[st] ;
    }

    while( st <= end ){

        int mid = st + (end-st)/2 ;

        // What if mid is at boundry of vector 
        if(mid == 0 && vec[0] != vec[1]){
            return vec[0] ;
        }
        if(mid == size-1 && vec[size-1] != vec[size-2]){
            return vec[size-1] ;
        }

        // if vector contains more than 2 elements in it ( 3+ elements )
        if(vec[mid-1] != vec[mid] && vec[mid] != vec[mid+1]){
            return vec[mid] ;
        }
        if(mid % 2 == 0){ // left side is even 
            if(vec[mid] == vec[mid-1]){
                end = mid-2 ;
            }else{
                st = mid+2 ;
            }
        }else{ // Left side is odd
            if(vec[mid] == vec[mid-1]){
                st = mid+1 ;
            }else{
                end = mid-1 ;
            }
        }
    }

    return -1 ;
}

int main(){
    vector<int> vec = {1 ,1 ,2 ,2 ,3 ,5 ,5 ,6 ,6 ,7 ,7} ;
    int ans = SingleElement(vec) ;
    cout << "The single element in vector is : " << ans <<  endl ; 
}