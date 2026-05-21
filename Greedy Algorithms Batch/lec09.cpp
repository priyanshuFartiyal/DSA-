// Assignment QUestion 2

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string maxOddNum(string s){
    vector<int> possNum ;

    int val = stoi(s) ;
    if(val % 2 != 0 ){
        possNum.push_back(val) ;
    }
    
    for(int i = 0 ; i < s.length() ; i++){
        if((s[i]-'0') % 2 != 0){
            possNum.push_back(s[i]-'0') ;
        }
    }

    sort(possNum.rbegin() , possNum.rend()) ;
    
    return to_string(possNum[0]) ;
}

int main(){
    string s = "578" ;
    cout << "The maximum odd number from string : " << maxOddNum(s) << endl ;
}