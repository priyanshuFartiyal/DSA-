// Trappping Rainwater (Leetcode -> 42)

#include<iostream>
#include<vector>
using namespace std ;

int main(){
    vector<int> heights = {4,2,0,3,2,5} ;
    int n = heights.size() ;
    vector<int> leftMax(n,0) ; 
    vector<int> rightMax(n,0) ;

    leftMax[0] = heights[0] ; 
    rightMax[n-1] = heights[n-1] ;

    for(int i = 1 ; i < n ; i++){
        leftMax[i] = max(leftMax[i-1] , heights[i]) ;
    }
    for(int i = n-2 ; i >= 0 ; i--){
        rightMax[i] = max(rightMax[i+1] ,heights[i]) ;
    }

    int maxWater = 0 ;
    for(int i = 0 ; i < n ; i++){
        int currWater = min(leftMax[i] , rightMax[i]) - heights[i] ;
        maxWater += currWater ; 
    }

    cout << "Maximum Water Stored is : " << maxWater << endl ;
}