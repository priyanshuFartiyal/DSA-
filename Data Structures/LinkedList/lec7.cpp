// Doubly LinkedList (directly insert at specific position hi krdiya)

#include<iostream>
using namespace std ;

class Node{
    public:
    int data ;
    Node* next ;
    Node* prev ;
    Node(int val){
        data = val ;
        next = prev = NULL ;
    }
};

class List{
    public:
    Node *head ;
    Node *tail ;
    List(){
        head = tail = NULL ;
    }

    void insert(int val , int pos){
        Node *newNode = new Node(val) ;
        if(pos < 1){
            cout << "Invalid Position" ;
            return ;
        }
        if(pos == 1){
            if(head == NULL){
                head = tail = newNode ;
                return ;
            }else{
                newNode->next = head ;
                head->prev = newNode ;
                head = newNode ;
                return ;
            }
        }
        Node *temp = head ;
        for(int i = 1 ; i < pos-1 ; i++){
            if(temp == NULL){
                cout << "Invalid Position" ;
                return ;
            }
            temp = temp->next ;
        }
        newNode->next = temp->next ;
        newNode->prev = temp ;
        if(temp->next != NULL){
            temp->next->prev = newNode ;
        }
        temp->next = newNode ;
        if(newNode->next == NULL){
            tail = newNode ;
        }
        return ;
    }

    void remove(int pos){
        if(pos < 1 || head == NULL){
            cout << "Invalid request " << endl ;
            return ;
        }
        if(pos == 1){
            Node *temp = head ;
            if(head->next == NULL){
                delete head ;
                head = tail = NULL ;
            }else{
                head = head->next ;
                head->prev = NULL ;
                delete temp ;
            }
            return ;
        }
        Node *temp = head ;
        for(int i = 1 ; i <= pos-1 ; i++){
            if(temp == NULL){
                cout << "Invalid Position" ;
                return ;
            }
            temp = temp->next ;
        }
        temp->prev->next = temp->next ;
        if(temp->next != NULL) {
            temp->next->prev = temp->prev ;
        }
        temp->prev = NULL ;
        temp->next = NULL ;
        delete temp ;

    }
    
    void display(){
        Node *temp = head ;
        while(temp != NULL){
            cout << temp->data << "->" ;
            temp = temp->next ;
        }cout << "NULL" << endl ;
        return ;
    }
};

int main(){
    List ll ;
    ll.insert(1,1) ;
    ll.insert(2,2) ;
    ll.insert(3,3) ;
    ll.insert(4,4) ;
    ll.insert(5,5) ;

    ll.display() ;
    
    ll.remove(3) ;
    ll.remove(1) ;
    ll.display() ;
}