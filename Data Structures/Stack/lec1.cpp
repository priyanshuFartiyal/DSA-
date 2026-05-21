// Implementation of Stack using vector & Linkedlist 

#include<iostream>
#include<vector>
#include<List>
using namespace std ;

// stack implementation by linkedlist
class stack{
    list<int> ll ;
    public:
    void push(int val){
        ll.push_front(val) ;
        return ;
    }
    void pop(){
        ll.pop_front() ;
        return ;
    }
    int top(){
        return ll.front() ;
    }
    bool isempty(){
        return ll.size() == 0 ;
    }
};

/* // stack implementation by Vector 
class stack{
    vector<int> v ;
    public:
    void push(int val){
        v.push_back(val) ;
        return ;
    }
    void pop(){
        if(isempty()){
            cout << "Nothing to pop" ;
            return ;
        }
        v.pop_back() ;
        return ;
    }
    int top(){
        return v[v.size()-1] ;
    }
    bool isempty(){
        return v.size() == 0 ;
    }
}; */

int main(){
    stack s ;
    s.push(1) ;
    s.push(2) ;
    s.push(3) ;
    s.push(4) ;
    s.pop() ;
    cout << "Top = " << s.top() << endl ;
    s.push(12) ;
    cout << "Top = " << s.top() << endl ; 

    while(!s.isempty()){
        cout << s.top() << "->" ;
        s.pop() ;
    }
}
