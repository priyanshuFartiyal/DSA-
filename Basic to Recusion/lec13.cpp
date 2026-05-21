// Book Allocation -> O( n*logn )

#include<iostream>
#include<vector>
using namespace std ;

bool Is_mid_valid(vector<int> vec , int students , int mid){
    int st = 1 , sum = 0 ;
    for(int val : vec){
        if(val > mid){     // edge case (very important)
            return false ;
        }
        if(val + sum <= mid ){
            sum += val ;
        }else{
            st++ ;
            sum = val ;
        }
    }
    
    return st <= students ;
}

int BookAllocation(vector<int> vec , int size , int m){
    int st = 0 , ans = -1 ,end =0 ;
    for(int val : vec){
        end += val ;
    }

    if(m>size){
        return ans ;
    }

    while(st <= end){
        int mid = st + (end-st)/2 ;
        if(Is_mid_valid(vec , m , mid )){ // Move left for finding minimum of valid maximum
            ans = mid ;
            end = mid-1 ;
        }else{ // i.e there is a more possible value of minimum of maximum books for student
            st = mid + 1 ;
        }
    }
    return ans ;
}

int main(){
    vector<int> vec = {2 ,1 ,3 ,4} ;
    int n = vec.size() ;
    int m = 2 ; // No. of Students in question 
    int ans = BookAllocation(vec , n , m) ;
    cout << "Minimum of Maximum of Books any student can have is : " << ans ;
}