// Reverse word in string (Leetcode -> Q.151)

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std ;

int main(){
    string str = "The sky is pink" ;
    //  // My Approach 
    // int i = 0 ;
    // vector<char> ans ;
    // vector<char> vec ;
    // while(str[i] != '\0'){
    //     vec.push_back(str[i]) ;
    //     if(str[i] == ' '){
    //         reverse(vec.begin(),vec.end()) ;
    //         for(int j = 0 ; j < vec.size() ; j++){
    //             ans.push_back(vec[j]) ;
    //         }
    //         vec.clear() ;
    //     }
    //     i++ ;
    // }

    // //for last word when the loop breaks 
    // vec.push_back(' ') ;
    // for(int i = vec.size()-1 ; i >= 0 ; i--){
    //     ans.push_back(vec[i]) ;
    // }
    
    // reverse(ans.begin() , ans.end()) ;
    // for(int i = 0 ; i < ans.size() ; i++){
    //     cout << ans[i] ;
    // }

    
    // Mam's Approach 

    string ans = "" ;
    reverse(str.begin() , str.end()) ;
    for(int i = 0 ; i < str.length() ; i++){
        string word = "" ;
        while(i < str.length() && str[i] != ' '){
            word += str[i] ;
            i++ ;
        }
        if(word.length() != 0){
            reverse(word.begin() , word.end()) ;
            ans += " " + word ;
        }
    }
    cout << ans << endl ;
}