#include<iostream>
#include<vector>
using namespace std ;

int MaxActivites(vector<int> start , vector<int> end){
    // sort on basis of ending time  -> already given in question
    // select A0
    int count = 1;
    int endTime = end[0] ;
    for(int i = 1 ; i < start.size() ; i++){
        // select other activities 
        if(start[i] >= endTime){
            count++ ;
            endTime = end[i] ;
        }
    }

    return count ;
}

int main(){
    vector<int> vec1 = {1,3,0,5,8,5} ;
    vector<int> vec2 = {2,4,6,7,9,9} ; // sorted given
    int ans = MaxActivites(vec1 , vec2) ;
    cout <<"Maximum no. of activities that can be done simultaneously : " << ans << endl ;
}