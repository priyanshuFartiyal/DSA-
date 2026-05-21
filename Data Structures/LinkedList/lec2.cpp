// Reversing a linkedList

#include<iostream>
using namespace std ;

class Node{
    public:
    int data ;
    Node* next ;
    Node(int val){
        data = val ;
        next = NULL ;
    }
};

class List {
    Node *head ;
    Node *tail ;
    public :
    List(){
        head = tail = NULL ;
    }

    void insert(int val , int pos){
        Node *newNode = new Node(val) ;
        if(pos < 1 ){
            cout << "INvalid Position" ;
            return ;
        }
        if(pos == 1){
            if(head == NULL){
                head = tail = newNode ;
                return ;
            }else{
                newNode->next = head ;
                head = newNode ;
            }
            return ;
        }
        Node *temp = head ;
        for(int i = 1 ; i < pos-1 ; i++){
            temp = temp->next; 
        }
        newNode->next = temp->next ;
        temp->next = newNode ;
        if(newNode->next == NULL){
            tail = newNode ; // update tail if inserted at end 
        }
    }

    void reverse(){
        Node *prev = NULL ;
        Node *curr = head ;
        Node *nxt = NULL ;
        while(curr != NULL){
            nxt = curr->next ;
            curr->next = prev ;

            prev = curr ;
            curr = nxt ;
        }
        head = prev ;
    }

    void display(){
        Node *temp = head ;
        while(temp != NULL){
            cout << temp->data << "->" ;
            temp = temp->next ;
        }cout << "NULL" << endl ;
    }
};

int main(){
    List ll ;
    ll.insert(1,1);
    ll.insert(2,2);
    ll.insert(3,3);
    ll.insert(4,4);
    ll.insert(5,5);
    cout << "Before Reversing : " << endl;
    ll.display() ;
    cout << endl ;
    cout << "After Reversing : " << endl;
    ll.reverse() ;
    ll.display() ;

}