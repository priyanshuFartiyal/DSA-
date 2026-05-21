// Next Permutation (Leetcode -> Q.31)

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std ;

int main()
{
    vector<int> vec = {1 ,2 ,3 ,6 ,5 ,4} ;
    int size = vec.size() ;

    // finding pivot element
    int pivot = -1 ;
    for(int i = size-2 ; i >= 0 ; i++ ){
        if (vec[i] < vec[i+1]){
            pivot = i ;
            break ;
        }
    }

    if(pivot == -1){ // array like {6 ,5 ,4 ,3 ,2 ,1} -> in this case return least combination of this 
        reverse(vec.begin() , vec.end()) ;
    }else{    
        // find the second largest element after pivot and swap
        for(int i = size-1 ; i > pivot ; i--){
            if(vec[i] > vec[pivot]){
                swap(vec[i] , vec[pivot]) ;
                break ;
            }
        }
        // reverse the array after pivot position till size-1 index 
        int i = pivot+1 , j = size-1 ;
        while( i < j ){
            swap(vec[i] , vec[j]) ;
            i++ ; 
            j-- ;
        }
    }

    cout << "The next permutation is " ;
    for(int val : vec){
        cout << val << " " ;
    }
}