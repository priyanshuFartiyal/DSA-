// Find Missing and Repeated Values (Leetcode -> Q.2965)

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std ;

vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid , int n ){
    vector<int> ans ;
    unordered_set<int> s;
    int sum = 0 ; int repVal ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(s.find(grid[i][j]) != s.end()){
                ans.push_back(grid[i][j]) ;
                repVal = grid[i][j] ;
            }
            s.insert(grid[i][j]) ;
            sum += grid[i][j] ;
        }
    }
    int actualSum = n*n * (n*n + 1) / 2 ;
    int misNum = actualSum - (sum-repVal) ;
    ans.push_back(misNum) ;
    return ans ;
}

int main(){
    vector<vector<int>> grid = {{1,2,3},{4,5,8},{7,8,9}};
    int n = 3 ;
    vector<int> vec = findMissingAndRepeatedValues(grid , n) ;
    for(int val : vec){
        cout << val << " " ;
    }
}