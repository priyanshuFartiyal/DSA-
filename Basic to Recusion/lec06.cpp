// Binomial Exponentiation (Leetcode -> Q.50 Pow(x,n))

#include<iostream>
#include<vector>
using namespace std ;

// Here We can't do it with Linear time complexity becoz as per question the complexity
// must be less than O(n) .. so we use Binomial exponentiation -> O(log n)

double myPow(double x , int n)
{
    long binForm = n ;
    if(n < 0){
        x = 1/x ;
        n = -n ;
    }
    double ans = 1 ;
    while(binForm > 0){
        if(binForm % 2 == 1){
            ans *= x ;
        }
        x *= x ;
        binForm /= 2 ;
    }
    return ans ;
}

// Stock Buy & Sell (Leetcode Q. 121)


int MaxProf(vector<int> vec , int size){
    int maxProf = 0 ;
    int bestBuy = vec[0] ;
    for(int i = 1 ; i < size ; i++){
        if(vec[i] > bestBuy){
            maxProf = max(maxProf , vec[i]-bestBuy) ;
        }
        bestBuy = min(bestBuy , vec[i]) ;
    }
    return maxProf ;
}

int main(){

    // Pow(x,n)
    double ans1 = myPow(3.0 , 5) ;
    cout << "Answer is : " << ans1 << endl ;

    //Stock Buy & sell 
    vector<int> vec = {7,1,5,3,6,4} ;
    int size = vec.size() ;

    int ans2 = MaxProf(vec , size) ;
    cout << "Maximum profit can be : " << ans2 << endl ;
}




