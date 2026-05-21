// The Celebrity Probleme (Leetcode -> 277) -> Premium 

#include<iostream>
#include<vector>
#include<stack>
using namespace std ;

int findCeleb(vector<vector<int>> vec){
    int n = vec.size() ;
    stack<int> s ;
    for(int i = 0 ; i < n ; i++){
        s.push(i) ;
    }

    while(s.size() > 1)
    {
        int i = s.top() ; s.pop() ;
        int j = s.top() ; s.pop() ;

        if(vec[i][j] == 0){
            s.push(i) ;
        }else{
            s.push(j) ;
        }
    }

    int celeb = s.top() ;
    for(int i = 0 ; i < n ; i++){
        if(i != celeb && (vec[i][celeb] == 0 || vec[celeb][i] == 1)){
            return -1 ;
        }
    }
    return celeb ;
}

int main(){
    vector<vector<int>> vec = {{0,1,0} , {0,0,0} , {0,1,0}} ;
    int celeb = findCeleb(vec) ;

    cout << "Celebrity is : " << celeb << endl ;
}


