// Detecting Cycles in linkedList & 
// finding starting element of cycle & 
// removing cycle

#include<iostream>
using namespace std ;

class Node{
    public :
    int data ;
    Node *next ;
    Node(int val){
        data = val ;
        next = NULL ;
    }
};

class List {
    public:
    Node *head ;
    Node *tail ;
    List(){
        head = tail = NULL ;
    }
    void insert(int val , int pos){
        Node *newNode = new Node(val) ;
        if(pos < 1){
            cout << "invalid Position" << endl ;
            return ;
        }
        if(pos == 1){
            if(head == NULL){
                head = tail = newNode ;
                return ;
            }else{
                newNode->next = head ;
                head = newNode ;
            }return ;
        }
        Node *temp = head ;
        for(int i=1 ; i<pos-1 ; i++){
            if(temp == NULL){
                cout << "Invalid Position" << endl ;
                return ;
            }
            temp = temp->next ;
        }
        newNode->next = temp->next ;
        temp->next = newNode ;
        if(newNode->next == NULL){
            tail = newNode ; // updating tail if inserted node at end 
        }
        
    }

    bool detect(){
        Node *slow = head ;
        Node *fast = head ;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next ;
            fast = fast->next->next ;
            if(slow == fast) return true ;
        }
        return false ;
    }

    Node* startingElement(){
        Node *slow = head ;
        Node *fast = head ;
        bool cycleExist = false ;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next ;
            fast = fast->next->next ;
            if(slow == fast){
                cycleExist = true ;
                break ;
            }
        }
        if(!cycleExist){
            return NULL ;
        }

        slow = head ;
        while(slow != fast){
            slow = slow->next ;
            fast = fast->next ;
        }

        return fast ; // or slow 
    }

    void display(){
        Node *temp = head ;
        while(temp != NULL){
            cout << temp->data << "->" ;
            temp = temp->next ;
        }
        cout << "NULL" << endl ;
    }
};

int main(){
    List ll ;
    ll.insert(1,1);
    ll.insert(2,2);
    ll.insert(3,3);
    ll.insert(4,4);
    ll.insert(5,5);
    ll.display() ;

    ll.tail->next = ll.head->next->next;  // cycle from tail to node 3

    if(ll.detect()){
        cout << "Cycle exists " << endl ;
    }else {
        cout << "Cycle don't exist " << endl ;
    }

    Node *strt = ll.startingElement() ;
    cout << "Starting element of cycle : " << strt->data << endl ;
    
}

/* To remove cycle alll you need is to store prev value of fast pointer after detecting cylcle 
and assigning slow = head ... and as you get slow == fast .. update prev = NULL . */