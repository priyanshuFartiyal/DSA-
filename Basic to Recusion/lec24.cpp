// String Compression (Leetcode -> Q.443)

#include<iostream> 
#include<vector>
using namespace std ;

int main(){
    vector<char> chars = {'a','a','b','b','c','c','c'} ;
    
    // // My approach if in-place manupulation nhi krna hoga vector m
    // string ans = "" ;
    // for(int i = 0 ; i < chars.size() ; i++){
    //     char current = chars[i] ;
    //     int count = 0 ;
    //     while(i < chars.size() && chars[i] == current){
    //         count ++ ;
    //         i ++ ;
    //     }
    //     ans += current ;
    //     if(count > 1){
    //         ans += to_string(count) ;
    //     }
    //     i-- ;
    // }
    // cout << ans << endl ;

    int idx = 0 ;
    for(int i = 0; i < chars.size() ; i++){
        char curr = chars[i] ;
        int count = 0 ;
        while(i < chars.size() && curr == chars[i]){
            count ++ ; i++ ;
        }
        if(count == 1){
            chars[idx++] = curr ;
        }else{
            chars[idx++] = curr ;
            string num = to_string(count) ;
            for(char val : num){
                chars[idx++] = val ;
            }
        }
        i-- ;
    }
    chars.resize(idx) ;

    cout << "New compressed length = " << idx << endl ;
    for(char val : chars){
        cout << val << " " ;
    }

}