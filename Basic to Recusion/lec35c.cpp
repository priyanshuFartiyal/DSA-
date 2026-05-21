// Printing Unique Subsets of any array by using extra set (Leetcode -> Q.78)

/* #include<iostream>
#include<set>
#include<vector> 
using namespace std ;

void subsets(vector<int> &nums , vector<int> &ans , int i , vector<vector<int>> &allUSubsets , set<vector<int>> &s){
    if(i == nums.size()){
        if(s.find(ans) == s.end()){
            allUSubsets.push_back(ans) ;
            s.insert({ans}) ;
        }
        return ;
    }

    ans.push_back(nums[i]) ;
    subsets(nums , ans , i+1 , allUSubsets , s) ;
    ans.pop_back() ;
    subsets(nums , ans , i+1 , allUSubsets , s) ;
}

int main(){
    vector<int> nums = {1,2,2} ;
    vector<int> ans ;
    vector<vector<int>> allUSubsets ;
    set<vector<int>> s ;
    subsets(nums , ans , 0 , allUSubsets , s ) ;
    for(int i = 0 ; i < allUSubsets.size() ; i++){
        for(int j = 0 ; j < allUSubsets[i].size() ; j++){
            cout << allUSubsets[i][j] << " ";
        }cout << endl ;
    }
} */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

void subsets(vector<int> &vec , vector<int> &ans , int i , vector<vector<int>> &allSubsets){
    if(i==vec.size()){
        allSubsets.push_back(ans) ;
        return ;
    }

    ans.push_back(vec[i]) ;
    subsets(vec , ans , i+1 , allSubsets) ;
    ans.pop_back() ;

    int idx = i ;
    while(idx+1 < vec.size() && vec[idx] == vec[idx+1]) idx++ ;
    subsets(vec , ans , idx+1 , allSubsets) ;
}

int main(){
    vector<int> vec = {1,2,2} ;
    sort(vec.begin() , vec.end()) ;

    vector<vector<int>> allSubsets ;
    vector<int> ans ;
    subsets(vec , ans , 0 , allSubsets) ;
    for(int i = 0 ; i < allSubsets.size() ; i++){
        for(int j = 0 ; j < allSubsets[i].size() ; j++){
            cout << allSubsets[i][j] << " ";
        }cout << endl ;
    }
}