// Linked List Basic operation -> push_front , push_back , pop_front , pop_back , insert at pos , print

#include<iostream>
using namespace std ;

class Node{
    public:
        int data ;
        Node *next ;

        Node(int val){
            data = val ;
            next = NULL ;
        }
};

class List{
    Node *head ;
    Node *tail ;

    public:
        List(){
            head = tail = NULL ;
        }

        void push_front(int val){
            Node *newNode = new Node(val) ;
            if(head == NULL){
                head = tail = newNode ;
                return ;
            }else{
                newNode->next = head ;
                head = newNode ;
            }
        }

        void pop_front(){
            if(head == NULL){
                cout << "Nothing to delete in List now" << endl ;
                return ;
            }else{
                Node *temp = head ;
                head = head->next ;
                temp->next = NULL ;
                delete temp ;
            }
        }

        void push_back(int val){
            Node *newNode = new Node(val) ;
            if(head == NULL){
                head = tail = newNode ;
                return ;
            }else{
                tail->next = newNode ;
                tail = newNode ; 
            }
        }

        void pop_back(){
            if(head == NULL){
                cout << "Nothing to delete from list now" << endl ;
            }else{
                // one element case 
                if(head == tail){
                    delete head ;
                    head = tail = NULL ;
                    return ;
                }

                Node *temp = head ;
                while(temp->next != tail){
                    temp = temp->next ;
                }
                temp->next = NULL ;
                delete tail ;
                tail = temp ;
            }
        }

        void insert(int val , int pos){
            Node *newNode = new Node(val) ;
            if(pos < 1){
                cout << "Invalid Position" << endl ;
                return ;
            }
            if(pos == 1){
                push_front(val) ;
                return ;
            }
            Node *temp = head ;
            for(int i = 1 ; i < pos-1 ; i++){
                if(temp == NULL){
                    cout << "Invalid Position" << endl ;
                    return ;
                }
                temp = temp->next ;
            }
            newNode->next = temp->next ;
            temp->next = newNode ;

        }

        void printLL(){
            Node *temp = head ;
            if(head == NULL){
                cout << "List already empty " << endl ;
                return ;
            }
            while(temp != NULL){
                cout << temp->data << "->" ;
                temp = temp->next ;
            }cout << "NULL" << endl ;
        }
};


int main(){
    List ll ;
    ll.push_front(1) ;
    ll.push_front(2) ;
    ll.push_front(3) ;
    ll.push_back(4) ;
    ll.push_back(5) ;
    ll.pop_front() ;
    ll.pop_back() ;
    ll.printLL() ;

    ll.insert(6,3) ;
    ll.printLL() ;
}