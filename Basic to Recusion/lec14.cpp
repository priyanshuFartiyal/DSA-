// Painter Partition Problem -> O( n*logn )

#include<iostream>
#include<vector>
#include<climits>
using namespace std ;

bool IsMidValid(vector<int> vec , int mid , int m){
    int time = 0 , painter = 1 ;
    for(int val : vec){
        if(val > mid){ // edge case condition
            return false ;
        }
        if(val + time <= mid){
            time += val ;
        }else{
            painter ++  ;
            time = val ;
        }
    }

    return painter <= m ;
}

int painterPartition(vector<int> vec , int n , int m)
{
    /*
    Range of time
    min time = for each board 1 painter i.e (maximum of array)
    max time = only 1 painter paints every board i.e (sum of array)
    */ 
    int res = -1 ;
    int st = INT_MAX ;
    int end = 0 ; 
    for(int val : vec){
        end += val ;
        st = min(st , val) ;
    }

    while(st <= end){
        int mid = st + (end-st)/2 ;

        if(IsMidValid(vec , mid , m)){
            res = mid ;
            end = mid-1 ;
        }else{
            st = mid + 1 ;
        }
    }

    return res ;

}

int main()
{
    vector<int> vec = {40 ,30 ,10 ,20} ; // Boards
    int size = vec.size() ;
    int painter = 2 ; // Already given in question 

    int res = painterPartition(vec , size , painter) ;

    cout << "Minimum time taken by the painter would be : " << res << endl ;
}