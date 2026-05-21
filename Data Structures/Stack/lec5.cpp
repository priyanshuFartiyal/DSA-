// Previous Smaller Element

#include<iostream>
#include<stack>
#include<vector>
using namespace std ;

int main(){
    vector<int> vec = {3,1,0,8,6} ;

    stack<int> s ;
    vector<int> ans ;

    for(int i = 0 ; i < vec.size() ; i++){
        while(!s.empty() && s.top() >= vec[i]){
            s.pop() ;
        }
        if(s.empty()){
            ans.push_back(-1) ;
        }else{
            ans.push_back(s.top()) ;
        }
        s.push(vec[i]) ;
    }

    for(int val : ans){
        cout << val << " " ;
    }
}