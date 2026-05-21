#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

int aggressiveCow(vector<int> vec , int size , int m){
    int low = 1 ;
    int high = max_element(vec.begin() , vec.end()) - min_element(vec.begin() , vec.end()) ;
    int ans = INT_MAX ;
    int st = low ;
    int end = high ;
    while(st < end){
        int mid = st + (end-st)/2 ;
        if(isMidValid){
            ans = min(ans , mid) ;
            end = mid-1 ;
        }else{
            
        }
    }
}


int main(){
    vector<int> vec = {1 ,2 ,8 ,4 ,9} ;
    int m = 3 ;
    int size = vec.size() ;
    int ans = aggressiveCow(vec , size , m) ;
}