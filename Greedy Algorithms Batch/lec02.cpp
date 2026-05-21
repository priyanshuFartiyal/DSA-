// What if pairs are not sorted in terms of end vector

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

bool compare(pair<int,int> p1 , pair<int,int> p2){
    return p1.second < p2.second ; // ascending end order 
}

int main(){
    vector<int> start = {0,1,2} ;
    vector<int> end = {9,2,4} ;

    // Initiate a vector that holds pairs value initially as 0
    vector<pair<int,int>> activity(start.size() , make_pair(0,0)) ;
    // assign values to vector
    activity[0] = make_pair(0,9) ;
    activity[1] = make_pair(1,2) ;
    activity[2] = make_pair(2,4) ;
    // Now you have sucessfully converted two seperated vectors into a vector 
    // of holding pairs of starting and ending time of activity
    for(int i = 0 ; i < start.size() ; i++){
        cout << activity[i].first << "," << activity[i].second << endl ;
    }

    // Now we need to sort the pair on the basis of second(end) values of vector of pair
    sort(activity.begin() , activity.end() , compare) ;

    cout << "-------------- After Sorting ----------------" << endl ;
    for(int i = 0 ; i < start.size() ; i++){
        cout << activity[i].first << "," << activity[i].second << endl ;
    }

}