// Subarray Sum Equals K

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std ;

// // Brute Force Approach 
// int subArray(vector<int> vec , int target){
//     int n = vec.size() ;
//     int count = 0 ;
//     for(int i = 0 ; i < n ; i++){
//         int sum = 0 ;
//         for(int j = i ; j < n ; j++){
//             sum += vec[j] ;
//             if(sum==target) count ++ ;
//         }
//     }
//     return count ;
// }

int subArray(vector<int> &vec , int k){
    int n = vec.size() ;
    int count = 0 ;
    vector<int> prefSum(n , 0) ;
    prefSum[0] = vec[0] ;
    for(int i = 1 ; i < n ; i++){
        prefSum[i] = prefSum[i-1]+vec[i] ;
    }

    unordered_map<int , int> m ; // PS , freq
    for(int j = 0 ; j < n ; j++){
        if(prefSum[j] == k) count ++ ;
        
        int val = prefSum[j] - k ;
        if(m.find(val) != m.end()){
            count += m[val] ;
        }

        if(m.find(prefSum[j]) == m.end()){
            m[prefSum[j]] = 0 ; 
        }
        m[prefSum[j]]++ ;
    }
    return count ;
    
}

int main(){
    vector<int> vec = {9,4,0,20,3,10,5} ;
    int target = 33 ;
    int ans = subArray(vec , target) ;
    cout << "No. of subarray sum equals " << target << " : " << ans << endl ;
}

