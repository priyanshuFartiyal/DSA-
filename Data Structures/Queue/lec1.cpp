// Basic Queue Operations and Deque  (Implementation by linkedlist)

#include<iostream>
#include<queue>
#include<vector>
#include<deque>
using namespace std ;

/*                 this is queue implementation by linkedlist from scratch 
class Node{
    public:
    int data ;
    Node* next ;
    Node(int val){
        data = val ;
        next = NULL ;
    }
};

class Queue{
    Node *head ;
    Node *tail ;
    public:
    Queue(){
        head = tail = NULL ;
    }

    void push(int val){
        Node *newNode = new Node(val) ;
        if(isempty()){
            head = tail = newNode ;
            return ;
        }
        tail->next = newNode ;
        tail = newNode ;  
    }

    void pop(){ 
        if(isempty()){
            cout << "Nothing to delete from queue" ;
            return ;
        }
        Node *temp = head ;
        head = head->next ;
        delete temp ;
    }

    int front(){
        if(isempty()){
            cout << "List empty" ;
            return -1 ;
        }
        return head->data ;
    }

    bool isempty(){
        if(head == NULL) return true ;
        return false ;
    }

}; 

int main(){
    Queue q ;
    q.push(1) ;
    q.push(2) ;
    q.push(3) ;
    while(!q.isempty()){
        cout << q.front() << "->" ;
        q.pop() ;
    }cout << "NULL" << endl ;
} */


/*                           implementation of queue by STL directly 
int main(){
    queue<int> q ;
    q.push(1) ;
    q.push(2) ;
    q.push(3) ;
    while(!q.empty()){
        cout << q.front() << "->" ;
        q.pop() ;
    }cout << "NULL" << endl ;
}
 */


//                 deque -> push and pop can be done from both ends and have front() as well as back() function
 int main(){
    deque<int> q ;
    q.push_back(1) ;
    q.push_back(2) ;
    q.push_back(3) ;
    q.push_front(4) ;
    q.push_front(5) ;

    while(!q.empty()){
        cout << q.front() << "->" ;
        q.pop_front() ;
    }cout << "NULL" << endl ;
    
 }

