// Nearest Car 
// Based on Car locations (cx , cy) , find nearest k cars.

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Car{
    public:
    int idx ;
    int distSq ;
    Car(int idx , int distSq){
        this->idx = idx ;
        this->distSq = distSq ;
    }

    bool operator < (const Car &obj) const{
        return this->distSq > obj.distSq ; // making min heap 
    }
};

void nearbyCars(vector<pair<int,int>> pos , int K){
    // Go through each pair and make object of each car data also save it to vector 
    vector<Car> cars ;
    for(int i = 0 ; i < pos.size() ; i++){
        int distSq = (pos[i].first*pos[i].first) + (pos[i].second*pos[i].second);
        cars.push_back(Car(i , distSq)) ;
    }

    priority_queue<Car> pq(cars.begin() , cars.end()) ; // O(n) -> saved time form O(nlogn)

    for(int i = 0 ; i < K ; i++){ // O(k*logn)
        cout << "Car " << pq.top().idx << endl ;
        pq.pop() ; // O(logn)
    }

}

int main(){
    vector<pair<int,int>> pos ;
    pos.push_back(make_pair(3,3)) ;
    pos.push_back(make_pair(5,-1)) ;
    pos.push_back(make_pair(-2,4)) ;

    int K = 1 ; // number of nearby cars = 2 ( 2 nearest car nikalo )

    nearbyCars(pos , K) ;

}

// Based on this techniques i solved some leetcode questions 
// Q. 973 , 658 , 251 , 347 (all medium level)