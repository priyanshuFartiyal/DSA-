// 4 Sum (Leetcode -> Q.18)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

vector<vector<int>> fourSum(vector<int> vec , int target){
    int n = vec.size() ; 
    vector<vector<int>> ans ;

    sort(vec.begin() , vec.end()) ;
    for(int i = 0 ; i < n ; i++){
        if(i > 0 && vec[i] == vec[i-1]) continue ;
        for(int j = i+1 ; j < n ; j++){
            if(j > 1 && vec[j] == vec[j-1]) continue ;
            int p = j+1 , q = n-1 ;
            while(p < q){
                if(vec[i]+vec[j]+vec[p]+vec[q] < target){
                    p++ ;
                }else if(vec[i]+vec[j]+vec[p]+vec[q] > target){
                    q-- ;
                }else{
                    ans.push_back(vec[i] , vec[j] , vec[p] , vec[q]) ;
                    p++ ;
                    q-- ;
                }
            }
        }
    }

    return ans ;
}

int main(){
    vector<int> vec = {-2,-1,-1,1,1,2,2} ;
    int target = 0 ;

    vector<vector<int>> vec = fourSum(vec , target) ;

    for(int i = 0 ; i < vec.size() ; i++){
        for(int j = 0 ; j < vec[0].size() ; j++){
            cout << vec[i][j] << " " ;
        }cout << endl ;
    }

}
