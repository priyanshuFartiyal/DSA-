// Peak Index in Mountain Array (Leetcode -> Q.852)

#include<iostream>
#include<vector>
using namespace std ;

int peakIndex(vector<int> vec ){
    int size = vec.size() ;
    int st = 1 , end = size-2 ;
    while(st <= end){
        int mid = st + (end-st)/2 ;
        if(vec[mid-1] < vec[mid] && vec[mid] > vec[mid+1] ){
            return mid ;
        }
        if(vec[mid] < vec[mid-1]){ // Mid on right side slant of mountain
            end = mid-1 ;
        }else{ // Mid on left side slant of mountain
            st = mid+1 ;
        }
    }
    return -1 ;
}

int main(){
    vector<int> vec = {1 ,2 ,4 ,5 ,8 ,9 ,3 ,2 ,0} ;
    int ans = peakIndex(vec) ;
    cout << "Peak element is present at index : " << ans ;
}