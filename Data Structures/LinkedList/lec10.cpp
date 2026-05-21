// Reverse Node for k Groups

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

class List{
    public:
    Node *head ;
    Node *tail ;
    List(){
        head = tail = NULL ;
    }
    void insert(int val , int pos){
        Node* newNode = new Node(val) ;
        if(pos < 1){
            cout << "Invalid Position" << endl ;
            return ;
        }
        if(pos ==  1){
            if(head == NULL){
                head = tail = newNode ;
                return ;
            }else{
                newNode->next = head ;
                head = newNode ;
                return ;
            }
        }
        Node* temp = head ;
        for(int i = 1 ; i < pos-1 ; i++){
            if(temp== NULL){
                cout << "Invalid Position" ;
                return ;
            }
            temp = temp->next ;
        }
        newNode->next = temp->next ;
        temp->next = newNode ;
        if(newNode->next == NULL){
            tail = newNode ;
        }
        return ;
    }

    void display(){
        Node *temp = head ;
        while(temp != NULL){
            cout << temp->data << "->" ;
            temp = temp->next ;
        }cout << "NULL" << endl ;
    }

    Node* reverseList(Node * head , int k){
        Node *temp = head ;
        int count = 0 ;

        while(count < k){
            if(temp == NULL ) return head ;
            temp = temp->next ;
            count++ ;
        }

        Node* prevHead = reverseList(temp , k) ;

        temp = head ;
        count = 0 ;
        Node*nextNode ;
        while(count < k){
            nextNode = temp->next ;
            temp->next = prevHead ;
            prevHead = temp ;
            temp = nextNode ;
            count++ ;
        }
        return prevHead ;
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
    ll.head = ll.reverseList(ll.head , 2) ;
    ll.display() ;
}