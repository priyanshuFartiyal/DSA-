// Storing all possible subsets of set of unique elements (Leetcode -> Q.78)

#include<iostream>
#include<vector>
using namespace std ;

void subsets(vector<int> &nums , vector<int> &ans , int i , vector<vector<int>> &allSubsets){
    if(i == nums.size()){
        allSubsets.push_back(ans) ;
        return ;
    }

    ans.push_back(nums[i]) ;
    subsets(nums , ans , i+1 , allSubsets) ;
    ans.pop_back() ;
    subsets(nums , ans , i+1 , allSubsets) ;
}

int main(){
    vector<int> nums = {1,2,3} ;
    vector<int> ans ;
    vector<vector<int>> allSubsets ;
    subsets(nums , ans , 0 , allSubsets) ;

    for(int i = 0 ; i < allSubsets.size() ; i++){
        for(int j = 0 ; j < allSubsets[i].size() ; j++){
            cout << allSubsets[i][j] << " " ;
        }cout << endl ;
    }
}