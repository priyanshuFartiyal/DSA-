// Majority Element

#include<iostream>
using namespace std ;


int main(){

    int arr[] = {1,2,2,1,1} ;
    int size = sizeof(arr)/sizeof(int) ;
   
    // Brute Force Approach ( n*n )
    for(int i = 0 ; i < size ; i++){
        int count = 0 ;
        for(int j = 0 ; j<size ; j++){
            if(arr[i]==arr[j]){
                count ++ ;
            }
        }
        if(count > size/2){
            cout << arr[i] << " is the majority element" << endl;
            break ;
        }
    }

    // Optimized Way ( n*logn )
    // By Merge Sort we can sort array in nlogn time complexity then by looping once on
    // array we can get the majority element .

    int arr2[] = {1,1,1,2,2} ;
    int freq = 1 , maj = arr2[0] ;
    for(int i = 1 ; i < size ; i++){
        if(arr2[i]==maj){
            freq++ ;
            if(freq > size/2){
                cout << arr2[i] << " is the majority element." << endl ;
                break ;
            }
        }else{
            freq = 1 ;
            maj = arr2[i] ;
        }
    }

    // Moore's Algorithm ( n )
    int arr3[] = {1,2,2,1,1} ;    
    int frequency = 0 , majority = arr3[0] ;
    for(int i = 0 ; i < size ; i++){
        if(frequency == 0){
            majority = arr3[i] ;
        }
        if(arr3[i]==majority){
            frequency++ ;
        }else{
            frequency -- ;
        }
    }
    cout << majority << " is the majority element." << endl ;


    
}