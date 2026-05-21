// 3 Sum (Leetcode -> Q.15)

#include<iostream>
#include<set>
#include<unordered_set>
#include<algorithm>
#include<vector>
using namespace std ;

// // Brute Force Approach -> O((n*n*n)*(log(uniqueTriplets)))
// vector<vector<int>> threeSum(vector<int>& vec ){
//     vector<vector<int>> ans ;
//     set<vector<int>> s ;
//     int n = vec.size() ;
//     for(int i = 0 ; i < n ; i++){
//         for(int j = i+1 ; j < n ; j++){
//             for(int k = j+1 ; k < n ; k++){
//                 if(vec[i]+vec[j]+vec[k] == 0){
//                     vector<int> nums = {vec[i] , vec[j] , vec[k]} ;
//                     sort(nums.begin() , nums.end()) ;
                    
//                     if(s.find(nums) == s.end()){
//                         s.insert(nums) ;
//                         ans.push_back(nums) ;
//                     }
//                 }
//             }
//         }
//     }
//     return ans ;
// }



// // Better Approach 

// vector<vector<int>> threeSum(vector<int>& vec ){
//     int n = vec.size() ;
//     set<vector<int>> uniqueTriplets ;
    
//     for(int i = 0 ; i < n ; i++){
//         int target = - vec[i] ;
//         set<int> s ;

//         for(int j = i+1 ; j < n ; j++){
//             int c = target-vec[j] ;
//             if(s.find(c) != s.end()){
//                 vector<int> trip = {vec[i] , vec[j] , c}  ;
//                 sort(trip.begin() , trip.end()) ;
//                 uniqueTriplets.insert(trip) ;
//             }
//             s.insert(vec[j]) ;
//         }
//         vector<vector<int>> ans(uniqueTriplets.begin() , uniqueTriplets.end()) ;
//         return ans ;
//     }
    
// }

// Optimize Solution
vector<vector<int>> threeSum(vector<int> &vec){
    vector<vector<int>> ans ;
    int n = vec.size() ;
    sort(vec.begin() , vec.end()) ;
    for(int i = 0 ; i < n ; i++){
        if(i > 0 && vec[i] == vec[i-1]) continue ;
        int target = - vec[i] ;
        int st = i+1 , end = n-1 ;
        while(st < end){
            if(vec[st]+vec[end] == target){
                ans.push_back({vec[i] , vec[st] , vec[end]}) ;
                st++ , end-- ;
                while(st < end && vec[st] == vec[st-1]) st ++ ;
                while(st < end && vec[end] == vec[end+1]) end--;

            }else if(vec[st]+vec[end] < target){
                st++ ;
            }else{
                end-- ;
            }

        }
    }
    return ans ;
}

int main(){
    vector<int> vec = {-1 ,0 ,1 ,2 , -1 ,-4} ;
    vector<vector<int>> ans = threeSum(vec) ;
    for(int i = 0 ; i < ans.size() ; i++){
        for(int j = 0 ; j < ans[i].size() ; j++){
            cout << ans[i][j] << " " ;
        }cout << endl ;
    }
}