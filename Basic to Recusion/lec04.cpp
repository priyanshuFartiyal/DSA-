// Two Sum 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

// Order of n*n
vector<int> twoSum(vector<int> vec , int target){
    vector<int> ans ;
    int size = vec.size() ;
    for(int i = 0 ; i < size ; i++){
        for(int j = i+1 ; j < size ; j++){
            if(vec[i] + vec[j] == target){
                ans.push_back(i) ;
                ans.push_back(j) ;
                return ans ;
            }
        }
    }
    return ans ;
}

// used two pointer approach which can only be used for sorted array .


vector<int> TwoSum(vector<int> vec , int target){
    
    sort(vec.begin() , vec.end()) ; // can directly sort array or vector but remember 
                                    // to use #include<algorithm> to use in header files
    vector<int> ans ;
    int size = vec.size() ;
    int i = 0 , j = size-1 ;
    while(i < j){
        int sum = vec[i] + vec[j] ;
        if(sum < target){
            i++ ;
        }else if(sum > target){
            j-- ;
        }
        else{
            ans.push_back(i) ;
            ans.push_back(j) ;
            return ans ;
        }
    }
    return ans ;
}

int main()
{
    vector<int> vec = {2 , 7 , 11 , 15} ;
    int target = 26 ;
    
    vector<int> ans1 = twoSum(vec , target) ;
    cout << "(" << ans1[0] << " , " << ans1[1] << ")" << endl ;

    vector<int> ans2 = TwoSum(vec , target) ;
    cout << "(" << ans2[0] << " , " << ans2[1] << ")" << endl ;

}