// Largest Rectangle in Histogram (Leetcode -> 84)

#include<iostream>
#include<stack>
#include<vector>
using namespace std ;

int main(){
    vector<int> heights = {2,1,5,6,2,3} ;
    int n = heights.size() ;

    vector<int> leftMin(n , -1) ;
    vector<int> rightMin(n , -1) ;
    stack<int> s ;
    for(int i = 0 ; i < n ; i++){
        while(!s.empty() && heights[s.top()] >= heights[i]){
            s.pop() ;
        }
        if(s.empty()){
            leftMin[i] = -1;
        }else{
            leftMin[i] = s.top() ;
        }
        s.push(i) ;
    }
    for(int i = n-1 ; i>= 0 ; i--){
        while(!s.empty() && heights[s.top()] >= heights[i]){
            s.pop() ;
        }
        if(s.empty()){
            rightMin[i] = heights[i] ;
        }else{
            rightMin[i] = s.top() ;
        }
        s.push(i) ;
    }

    int maxArea = 0 ;
    for(int i = 0 ; i < n ; i++ ){
        int width = rightMin[i] - leftMin[i] - 1;
        int currArea = heights[i] * width ; 
        maxArea = max(currArea , maxArea) ;
    }
    cout << "Maximum Reactangle area = " << maxArea << endl ;
}