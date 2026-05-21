// Printing Subsets 

#include<iostream>
#include<vector>
using namespace std ;

void printSubset(vector<int> vec , vector<int> ans , int i){
    if(i == vec.size()){
        for(int val : ans){
            cout << val ;
        }cout << endl ;
        return ;
    }

    ans.push_back(vec[i]) ;
    printSubset(vec , ans , i+1) ;
    ans.pop_back() ;
    printSubset(vec , ans , i+1) ;
}

int main(){
    vector<int> vec = {1,2,3} ;
    vector<int> ans ;
    printSubset(vec , ans , 0) ;
}
