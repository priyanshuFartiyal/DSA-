// Heap Sort 

#include<iostream>
#include<vector>
using namespace std;

void heapify(int i , vector<int> &vec , int n){   // To fix the heap 
    int left = 2*i + 1 ;
    int right = 2*i + 2 ;
    int maxI = i ;

    if(left < n && vec[left] > vec[maxI]){
        maxI = left ;
    }

    if(right < n && vec[right] > vec[maxI]){
        maxI = right ;
    }

    if(maxI != i){
        swap(vec[i] , vec[maxI]) ;
        heapify(maxI , vec , n) ;
    }
}

void heapSort(vector<int> &vec){
    int n = vec.size() ;
    // Step 1 : To make max heap first 
    for(int i = n-1/2 ; i >= 0 ; i--){
        heapify(i , vec , n) ;
    }

    // Step 2 : To sort it in ascending order by interchanging first & last element & reducing size of vector 
    for(int i = n-1 ; i >= 0 ; i--){
        swap(vec[0] , vec[i]) ;
        heapify(0 , vec , i) ;
    }
}

int main(){
    vector<int> vec = {3,4,1,2,5};
    heapSort(vec) ;

    // Printing ascendingly Sorted array 
    for(int val : vec){
        cout << val << " " ;
    }cout << endl ;
}