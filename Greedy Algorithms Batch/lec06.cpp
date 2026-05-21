// Indian Coins 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minCoins(vector<int> &coins , int &amount){
    int ans = 0 ; 
    sort(coins.begin() , coins.end()) ; // if unsorted then required 
    for(int i = coins.size()-1 ; amount > 0 && i >= 0 ; i--){
        if(amount >= coins[i]){
            ans += amount / coins[i] ;
            amount = amount % coins[i] ;
        }
    }

    return ans ;
}

int main(){
    vector<int> coins = {1,2,5,10,20,50,100,500,2000} ; // sorted given as per question but may be unsorted
    int amount = 1094 ;
    cout << "Min no. of coins required to pay : " << minCoins(coins , amount) << endl ;
}
