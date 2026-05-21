// Maximum length Chain of Pairs

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> p1 , pair<int,int> p2){
    return p1.second < p2.second ; // end - ascending 
}

int maximumChainLength(vector<pair<int,int>> pairs){

    sort(pairs.begin() , pairs.end() , compare) ;

    int length = 1 ;
    int endLength = pairs[0].second ;
    for(int i = 1 ; i < pairs.size() ; i++){
        if(pairs[i].first >= endLength){
            length++ ;
            endLength = pairs[i].second ;
        }
    }
    return length ;
}

int main(){
    int n = 5 ;
    vector<pair<int,int>> pairs(n, make_pair(0,0)) ;
    pairs[0] = make_pair(5,24) ;
    pairs[1] = make_pair(39,60) ;
    pairs[2] = make_pair(5,28) ;
    pairs[3] = make_pair(27,40) ;
    pairs[4] = make_pair(50,90) ;

    cout << "Maximum length of pairs is : " << maximumChainLength(pairs) << endl ;
}