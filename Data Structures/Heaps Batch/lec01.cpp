// Priority Queue

#include<iostream>
#include<queue>
using namespace std;

int main(){

    // In priority queue by default queue top element is the largest element ( Max. heap )

    priority_queue<int> pq ;

    pq.push(5) ;
    pq.push(10) ;
    pq.push(3) ;

    // Push()
    cout << "Top element : " << pq.top() << endl << endl ;

    // Pop()
    while(!pq.empty()){
        cout << "Top element : " << pq.top() << endl ;
        pq.pop() ;
    } 

    cout << endl << endl ;

    // You can flip the priority of queue by passing some more arguments while declaring it ( Min Heap )
    priority_queue<int , vector<int> , greater<int>> pq2 ;
    // Now in this priority queue , the priority is the smallest element
    pq2.push(5) ;
    pq2.push(10) ;
    pq2.push(3) ;

    while(!pq2.empty()){
        cout << "Top element : " << pq2.top() << endl ;
        pq2.pop() ;
    }



}