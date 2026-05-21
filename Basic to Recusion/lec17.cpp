// Dutch National Flag Algorihtm (Leetcode -> Q.75)

#include<iostream>
#include<vector>
using namespace std ;

void DNFsorting(vector<int> &vec , int size)
{
    int low = 0 , mid = 0 , high = size-1 ;
    while(mid <= high){
        if(vec[mid] == 0 ){
            swap(vec[mid] , vec[low]) ;
            mid++ ;
            low++ ;
        }else if(vec[mid] == 1){
            mid++ ;
        }else{
            swap(vec[mid] , vec[high]) ;
            high -- ;
        }
    }
}

int main()
{
    vector<int> vec = { 1 ,0 ,2 ,1 ,0 , 2 ,0 ,1 ,2 ,1} ;
    int size = vec.size() ;
    DNFsorting(vec , size) ;
    for(int val : vec){
        cout << val << " " ;
    }
}   