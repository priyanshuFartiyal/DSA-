// Permutation in string (Leetcode -> Q.567)

#include<iostream>
#include<vector>
using namespace std ;

bool isFreqSame(int freq1[] , int freq2[]){
    for(int i = 0 ; i < 26 ; i++){
        if(freq1[i] != freq2[i]){
            return false ;
        }
    }
    return true ;
}

bool checkInclusion(string st1 , string st2){
    int freq1[26] = {0} ;
    for(int i = 0 ; i < st1.length() ; i++){
        freq1[st1[i]-'a']++ ;
    }

    int windSize = st1.length() ;

    for(int i = 0 ; i < st2.length() ; i++){
        int windIdx = 0 , idx = i ;
        int freq2[26] = {0} ; 

        while(windIdx < windSize && idx < st2.length()){
            freq2[st2[idx]-'a'] ++ ;
            idx++ ;
            windIdx++ ;
        }

        if(isFreqSame(freq1 , freq2)){
            return true ;
        }
    }
    return false ;
}

int main(){
    string st1 = "ab" ;
    string st2 = "xyapbaecwuo" ;
    if(checkInclusion(st1 , st2)){
        cout << "Found " << endl ;
    }else{
        cout << "Not Found" << endl ;
    }
}