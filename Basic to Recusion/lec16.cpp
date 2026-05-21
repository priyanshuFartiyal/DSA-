// Sorting 

#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std ;

void swap(int *x , int *y){
    int temp = *x ;
    *y = *x ;
    *y = temp ;
}

void BubbleSort(vector<int> vec){
    int size = vec.size() ;
    for(int i = 0 ; i < size-1 ; i++){
        for(int j = 0 ; j < size-1-i ; j++){
            if(vec[j] > vec[j+1]){
                swap(vec[j] , vec[j+1]) ;
            }
        }
    }
}

void printVector(vector<int> vec ){
    for(int i = 0 ; i < vec.size() ; i++){
        cout << vec[i] << " " ;
    }
}

void SelectionSort(vector<int> &vec){
    int size = vec.size() ;
    for(int i = 0 ; i < size-1 ; i++){
        int minIndex = i ;
        for(int j = i+1 ; j < size ; j++){
            if(vec[j] < vec[minIndex]){
                minIndex = j ;
            }
        }
        if(vec[i] != vec[minIndex]){
            swap(vec[minIndex] , vec[i]) ;
        }
    }
}

void InsertionSort(vector<int> &vec){
    int size = vec.size() ;
    for(int i = 1 ; i < size ; i++){
        int j = i-1 ;
        while(j >= 0 && vec[j] < vec[i]){
            --j ;
            swap(vec[j+1] , vec[i]) ; 
        }
           
    }
}

int main()
{
    vector<int> vec = {2 ,4 ,1 ,7 ,5 , 6} ;
    // BubbleSort(vec) ;
    // SelectionSort(vec) ;
    InsertionSort(vec) ;
    printVector(vec) ;
}