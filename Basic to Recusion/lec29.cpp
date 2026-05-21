// Two Sum (Leetcode -> Q.1)

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std ;

vector<int> twoSum(int arr[] , int size , int target){
    vector<int> vec ;
    unordered_map<int,int> m ;
    for(int i = 0 ; i < size ; i++){
        int num = arr[i] ;
        int comp = target - num ;
        if(m.find(comp) != m.end()){
            vec.push_back(m[comp]) ;
            vec.push_back(i) ;
            return vec ;
        }
        m.emplace(num , i) ;
    }
    vec.push_back(-1) ;
    return vec ;
}

int main(){
    int arr[] = {5 , 2 , 11 , 7 , 15} ;
    int size = sizeof(arr)/sizeof(arr[0]) ;
    int target = 26 ;
    vector<int> vec = twoSum(arr ,size , target) ;
    for(int val : vec){
        cout << val << " " ;
    }
}