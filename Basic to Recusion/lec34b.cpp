// Is Array Sorted 

#include<iostream>
using namespace std ;

bool isArraySorted (int arr[], int n){
    if(n==0 || n==1){
        return true ;
    }

    return arr[n-1] >= arr[n-2] && isArraySorted(arr , n-1) ;
}

int main(){
    int arr[5] = {1,2,3,4,36} ;
    int size = sizeof(arr)/sizeof(arr[0]) ;
    cout << "Is array sorted : " << isArraySorted(arr , size) ;
}
