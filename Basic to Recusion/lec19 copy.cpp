// STL (Standard Template Library)

#include<iostream>
#include<vector>
#include<list> 
#include<deque>
#include<utility> //for pair
#include<stack>
#include<queue> // for priority queue also
#include<map>
#include<unordered_map>
using namespace std ;

int main()
{
    // vector<int> vec ;
    // vec.push_back(1) ;
    // vec.push_back(2) ;
    // vec.push_back(3) ;
    // vec.push_back(4) ;
    // vec.push_back(5) ;
    // vec.push_back(6) ;
    // cout << vec.front() << endl ;
    // cout << vec.back() << endl ;
    // vec.pop_back() ;

    // for(int val : vec){
    //     cout << val << " " ;
    // }cout << endl ;

    // list<int> l ;
    // l.push_back(1) ;
    // l.push_back(2) ;
    // l.push_front(0) ;
    // l.pop_back() ;
    // l.pop_front() ;
    
    // for(int val : l){
    //     cout << val << " " ;
    // }

    // pair<int , pair<char , int>> p = {2 , {'o' , 4} } ;
    // cout << p.first << endl ;
    // cout << p.second.first << endl ;
    // cout << p.second.second << endl ;

    // vector<pair<int,int>> vec = {{1,2} , {3,4} , {5,6}} ;
    // vec.push_back({7,8}) ; // only insert .
    // vec.emplace_back(9,0) ; // in-place object create .
    // for(pair<int,int> val : vec){
    //     cout << val.first << " , " << val.second << endl ;
    // }

    // stack<int> s ;
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // s.emplace(32) ;
    // s.pop() ;
    // cout << "Size of stack : " <<s.size() << endl ;
    // cout << "Top element : " << s.top() << endl ;
    // while(!s.empty()){
    //     cout << s.top() << endl ;
    //     s.pop() ;
    // }
    // stack<int> s2 ;
    // s2.swap(s) ; // Now s2 have all the elements of s and s is empty

    // queue<int> q ;
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);
    // q.pop() ;
    // cout << "Size of queue : " <<q.size() << endl ;
    // cout << "front element : " << q.front() << endl ;
    // while(!q.empty()){
    //     cout << q.front() << endl ;
    //     q.pop() ;
    // }
    // queue<int> q2 ;
    // q2.swap(q) ; // Now s2 have all the elements of s and s is empty

    // priority_queue<int> pq ;
    // pq.push(5);
    // pq.push(2);
    // pq.push(10);
    // pq.push(3);
    // cout << "Size of queue : " <<pq.size() << endl ;
    // cout << "top element : " << pq.top() << endl ;
    // while(!pq.empty()){
    //     cout << pq.top() << endl ;
    //     pq.pop() ;
    // }
    // priority_queue<int> pq2 ;
    // pq2.swap(pq) ; // Now s2 have all the elements of s and s is empty

    // map<string,int> m ;
    // m["TV"] = 100 ;
    // m["Laptop"] = 50 ;
    // m["Phones"] = 75 ;
    // m["Tablet"] = 120 ;
    // m["Headphones"] = 43 ;
    // m.insert({"Camera" , 55}) ;
    // for(auto p : m){
    //     cout << p.first << " " << p.second << endl ;
    // }

    // cout << "count : " << m.count("Laptop") << endl ;
    // m.erase("TV") ;
    // if(m.find("Camera") != m.end()){
    //     cout << "Found" << endl ;
    // }else{
    //     cout << "Not Found" << endl ;
    // }


    // multimap<string , int > mm ; // Ordering happenS & can have same name different keys 
    // mm.emplace("TV" , 100) ;
    // mm.emplace("AC" , 50) ;
    // mm.emplace("TV" , 75) ;
    // mm.emplace("Camera" , 55) ;

    // for(auto m : mm){
    //     cout << m.first << " " << m.second << endl ;
    // }

    // unordered_map<string ,int> um ; // Order of elements can be random not ordered .
    // um.emplace("TV" , 299) ;
    // um.emplace("SOfa" , 43) ;
    // um.emplace("Bed" , 83) ;
    
    // for(auto u : um){
    //     cout << u.first << " " << u.second << endl ;
    // }

    

}

