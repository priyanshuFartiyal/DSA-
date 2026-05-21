// Merge Sorted Array Problems (Leetcode -> Q.88)

#include<iostream>
#include<vector>
using namespace std ;

int main(){
    int A[] = { 1 ,2 ,3 ,0 ,0 ,0} ;
    int m = 3 ;
    int sizeA = 6 ; // size => m+n
    int B[] = { 2 ,5 ,6} ; 
    int n = 3 ; // size => n

    // You can do it with making extra space of m+n size and then compare
    // each element of both arrays then add it to final answer array.
    // But as per question you have to solve by space complexity as O(1) .

    int i = m-1 , j = n-1 , idx = sizeA - 1 ;
    while(i >= 0 && j >= 0){
        if(A[i] >= B[j]){
            A[idx] = A[i] ;
            i-- ;
            idx-- ;
        }else{
            A[idx] = B[j] ;
            idx-- ;
            j-- ;
        }
    }
    // If j become 0 before i -> No problem but if vice versq
    // then , backtracking of elements of B into array A  has to be done
    while(j >= 0){
        A[idx] = B[j] ;
        j-- ;
        idx-- ;
    }

    for(int i = 0 ; i < sizeA ; i++){
        cout << A[i] << " " ;
    }

}
