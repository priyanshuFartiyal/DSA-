// Search in 2-D Matrix (I) (Leetcode Q.74)

#include<iostream>
#include<vector>
using namespace std ;

bool searchInCol(vector<vector<int>> &mat , int target , int m , int n){
    int st = 0 , end = n-1 ;
    while(st <= end){
        int mid = st + (end-st)/2 ;
        if(mat[m][mid] == target){
            return true ;
        }else if (mat[m][mid] < target){
            st = mid + 1 ;
        }else{
            end = mid - 1 ;
        }
    }
    return false ;
}

bool SearchTargetInRow(vector<vector<int>> &mat , int target){
    int m = mat.size() ;
    int n = mat[0].size() ;
    int st = 0 , end = m-1 ;
    while(st <= end){
        int mid = st + (end-st)/2 ;
        if(mat[mid][0] <= target && mat[mid][n-1] >= target){
            //row found 
            if(searchInCol(mat , target , mid , n )){
                return true ;
            }return false ;
        }else if(mat[mid][0] > target){
            end = mid-1 ;
        }else if(mat[mid][n-1] < target){
            st = mid+1 ;
        }
    }
    return false ;
}

int main(){
    vector<vector<int>> vec = {{1,3,5,7},{10,11,16,20},{23,30,34,60}} ;
    int target = 118 ;
    cout << "Target present -> " << SearchTargetInRow(vec , target) << endl ;

}