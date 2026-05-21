// Fractional Knapsack 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> p1 , pair<int,int> p2){
    return p1.first > p2.first ; // descending on basis of first element
}

int maxValue(vector<int> value , vector<int> weight , int W , vector<pair<int,int>> ratio){
    int maximumValue = 0;

    for(int i = 0 ; i < value.size() ; i++){
        int idx = ratio[i].second ; 
        if(weight[idx] <= W){
            // Put weight as much as you can
            maximumValue += value[idx] ;
            W -= weight[idx] ;
        }else{
            // Put partial weight on sack 
            maximumValue += ratio[i].first * W ;
            W = 0 ;
            break ;
        }
    }
    return maximumValue ;
}

int main(){
    vector<int> value = {60,100,120} ;
    vector<int> weight = {10,20,30} ;
    int W = 50 ; // Weight of sack

    vector<pair<int,int>> ratio(value.size() , make_pair(0,0)) ;
    for(int i = 0 ; i < value.size() ; i++){
        ratio[i] = make_pair(value[i]/weight[i] , i) ;
    }

    // Ratios with index before sorting 
    for(int i = 0 ; i < value.size() ; i++){
        cout << ratio[i].first << " , " << ratio[i].second << endl ;
    }

    sort(ratio.begin() , ratio.end() , compare) ;
    cout << "---------------- After Sorting ---------------------" << endl ;

    // Ratios with index after sorting 
    for(int i = 0 ; i < value.size() ; i++){
        cout << ratio[i].first << " , " << ratio[i].second << endl ;
    }

    int ans = maxValue(value , weight , W ,ratio) ;

    cout << "Maximum Value Obtained : " << ans << endl ;
}