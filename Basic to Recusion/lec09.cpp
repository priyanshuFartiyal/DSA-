// Binary Sort 

#include<iostream>
#include<vector>
using namespace std ;

// Iterative Approach
int BinSearch(vector<int> vec , int target){
    int st = 0 , end = vec.size()-1 ;
    while(st <= end){
        int mid = st + (end-st)/2 ; // Optimization for not exceeding integer limit
        if(vec[mid] < target){
            st = mid+1 ;
        }else if(vec[mid] > target){
            end = mid-1 ;
        }else{
            return mid ;
        }
    }
    return -1 ;
}

// Recusive Approach 
int BinSrch(vector<int> vec , int target , int st , int end){
    int mid = st + (end-st)/2 ;
    while(st < end){
        if(vec[mid] < target){
            return BinSrch(vec , target , mid+1 , end) ;
        }else if(vec[mid] > target){
            return BinSrch(vec , target , st , mid-1) ;
        }else{
            return mid ;
        }
    }
    return -1 ;
}

int main(){
    vector <int> vec = {1 ,2 ,5 ,7 ,8} ;
    int size = vec.size() ;
    int target = 5 ;

    int res = BinSearch(vec ,  target) ;
    if(res!=-1){
        cout << "Element found at index : " << res << endl ;
    }else{
        cout << "Element Not Found !" << endl ;
    }

    int result = BinSrch(vec , target , 0 , size) ;
    if(result != -1){
        cout << "Element found at index : " << res << endl ;
    }else{
        cout << "Element Not Found !" << endl ;
    }
}