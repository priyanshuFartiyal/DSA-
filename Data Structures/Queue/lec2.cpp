// Circular Queue 

#include<iostream>
using namespace std ;

class circularQueue{
    int *arr ;
    int f , r ;
    int cap , currSize ;
    public:
    circularQueue(int size){
        cap = size ;
        currSize = 0 ;
        f = 0 ; r = -1 ;
        arr = new int[size] ;
    }

    void push(int val){
        if(currSize == cap){
            cout << "Circular Queue is full" << endl ;
            return ;
        }
        r = (r+1)%cap ;
        arr[r] = val ;
        currSize ++ ;
    };

    void pop(){
        if(isempty()){
            cout << "Nothing to pop " << endl ;
            return ;
        }
        f = (f+1) % cap ;
        currSize -- ;
    }

    int front(){
        if(isempty()){
            cout << "Is already empty" ;
            return -1 ;
        }
        return arr[f] ;
    }

    bool isempty(){
        if(r == -1) return true ;
        return false ;
    }

    void display(){
        if(isempty()){
            cout << "Queue is empty" ;
            return ;
        }
        while(currSize != 0){
            cout << arr[f] << "->" ;
            f = (f+1)%cap ;
            currSize -- ;
        }cout << "NULL" << endl ;
    }
};

int main(){
    circularQueue cq(3) ;
    cq.push(1) ;
    cq.push(2) ;
    cq.push(3) ; 
    cq.pop() ;
    cq.push(4) ;
    cq.display() ;

}