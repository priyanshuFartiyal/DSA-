// Pairs in PQ

#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

/* 
    // By default priority is set on the basis of first property of pairs : here its string i.e name 

    int main(){
        priority_queue<pair<string,int>> pq ;
        pq.push(make_pair("Aman" , 85)) ;
        pq.push(make_pair("Bhumika" , 95)) ;
        pq.push(make_pair("Chetan" , 65)) ;

        while(!pq.empty()){
            cout << pq.top().first << " , " << pq.top().second << endl ;
            pq.pop() ;
        }
    } 
*/

struct Comp{
    bool operator () ( pair<string , int> &p1 , pair<string , int> &p2 ) {
        return p1.second < p2.second ; // max heap on basis of marks (second property of pair)
    }
};

int main(){
    priority_queue<pair<string, int> , vector<pair<string , int>> , Comp > pq ;
    pq.push(make_pair("Aman" , 85)) ;
    pq.push(make_pair("Bhumika" , 95)) ;
    pq.push(make_pair("Chetan" , 65)) ;

    while(!pq.empty()){
        cout << pq.top().first << " , " << pq.top().second << endl ;
        pq.pop() ;
    }
}