// Agressive Cows Problem

// keep the agressive cows as far as possible in the given locations such that it should
// be maximum of minimum 

#include<iostream> // for using cout , cin 
#include<algorithm> // for sorting 
#include<climits> // for using INT_MAX , INT_MIN
#include<vector> // for using vector
using namespace std ;

bool IsMidPossible(vector<int> vec , int m , int mid){
    // We have to do sorting before checking about -> is the min distance possible ?
    sort(vec.begin() , vec.end()) ;
    // Now vector looks like -> [1 ,2 ,4 ,8 ,9]

    int cows = 1 , lastStallPos = vec[0] ;
    for(int val : vec){
        if(val-lastStallPos < mid){
            continue ;
        }else{
            cows++ ;
            lastStallPos = val ;
        }

        if(cows == m){
            return true ;
        }
    }

    return false;
}

int AgressiveCowsProblem(vector<int> vec , int m )
{
    int mini = INT_MAX , maxi = INT_MIN  , ans = -1;
    for(int val : vec){
        mini = min(mini , val) ;
        maxi = max(maxi , val) ;
    }
    int st = 1 ;
    int end = maxi-mini ;

    while(st <= end){
        int mid = st + (end-st)/2 ;
        if(IsMidPossible(vec , m , mid)){
            ans = mid ;
            st = mid+1 ;
        }else{
            end = mid-1 ;
        }
    }

    return ans ;
}

int main()
{
    vector<int> vec = {1 ,2 ,8 ,4 ,9} ; // stalls placements
    int m = 3 ; // No of cows 
    int n = vec.size() ; // size of array 

    int ans = AgressiveCowsProblem(vec , m ) ;
    cout << "The maximum of minimum distance between 3 cows in possible places can be : " << ans << endl ;
}
