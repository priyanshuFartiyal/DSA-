// Mininum Absolute Value 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

int main(){
    vector<int> v1 = {1,2,3} ;
    vector<int> v2 = {2,1,3} ;

    sort(v1.begin() , v1.end()) ;
    sort(v2.begin() , v2.end()) ;

    int absVal = 0 ;
    for(int i = 0 ; i < v2.size() ; i++){
        absVal += abs(v1[i] - v2[i]) ;           // abs() gives absolute value of any number 
    }

    cout << "Sum of Min absolute differences is : " << absVal << endl ;
}