// Combination Sum 

#include<iostream>
#include<vector>
#include<set>
using namespace std ;

set<vector<int>> st ;

void allCombinations(vector<int> &arr , int idx , int target , vector<int> &combin , vector<vector<int>> &ans){
    
    if(target == 0){
        if(st.find(combin) == st.end()){
            st.insert(combin) ;
            ans.push_back(combin) ;
        }
        return ;
    }

    if(idx == arr.size() || target < 0){
        return ;
    }

    combin.push_back(arr[idx]) ;
    allCombinations(arr , idx+1 , target-arr[idx] , combin , ans) ;
    allCombinations(arr , idx , target-arr[idx] , combin , ans) ;
    combin.pop_back() ;
    allCombinations(arr , idx+1 , target , combin , ans) ;

    
}

int main(){
    vector<int> arr = {2,3,5} ;
    int target = 8 ;
    vector<int> combin ;
    vector<vector<int>> ans ;
    allCombinations(arr , 0 , target , combin , ans) ;

    for(vector<int> comb : ans){
        for(int num : comb){
            cout << num << " " ;
        }
        cout << endl ;
    }
}