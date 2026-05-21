// Stock Span (Leetcode -> 901)

#include<iostream>
#include<vector>
#include<stack>
using namespace std ;

int main(){
    vector<int> vec = {100,80,60,70,60,75,85} ;
    stack<int> s ;
    vector<int> ans ;

    s.push(0) ;
    ans.push_back(1) ;
    for(int i = 1 ; i < vec.size() ; i++){
        while(!s.empty() && vec[s.top()] < vec[i]){
            s.pop() ;
        }
        if(s.empty()){
            ans.push_back(i+1) ;
        }else{
            ans.push_back(i-s.top()) ;
        }
        s.push(i) ;
    }

    for(int val : ans ){
        cout << val << " " ;
    }
}
