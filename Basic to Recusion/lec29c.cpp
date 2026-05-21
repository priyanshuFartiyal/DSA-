// Find the Duplicate Number (Leetcode -> Q.287)
// You can do it with unordered set method as before but the catch is to
//   do it with constant space complexity

/*
    1. Slow-Fast Pointer approach works of linkedlist 
    2. Here imagine givan array as linkedlist and 
        (i). index as nodes 
        (ii). values of those index as the next node pointer ;
    3. initiate slow & fast pointer from first index or element 
       then keep moving slow pointer by 1 step and fast pointer by
       two step till they become equal.
    4. Now assign the slow pointer again with first index or element 
       then the value at which both pointer meets again will become 
       the desired duplicate value (i.e first element of cycle in LL)
*/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std ;

int duplicateValue(int arr[] ){
    int slow = arr[0] ;
    int fast = arr[0] ;
    
    do{
        slow = arr[slow] ;
        fast = arr[arr[fast]] ;
    }while(slow != fast) ;

    slow = arr[0] ;

    while(slow != fast ){
        slow = arr[slow] ;
        fast = arr[fast] ;
    }

    return slow ; // or return fast ;
}

int main(){
    int arr[] = {3,1,2,1,4} ;
    int ans = duplicateValue(arr) ;
    cout << "Duplicate Value is : " << ans << endl ;
}