// Middle of the linkedList

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
            cout << "Invalid Position" ;
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
        for(int i = 1 ; i < pos-1 ; i++){
            if(temp == NULL){
                cout << "Invalid Position " << endl ;
                return ;
            }
            temp = temp->next ;
        }
        newNode->next = temp->next ;
        temp->next = newNode ;
        if(newNode->next == NULL){
            tail = newNode ; // if inserted element is at end
        }
    }

    Node* findMid(){
        Node *slow = head ;
        Node *fast = head ;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next ;
            fast = fast->next->next ;
        }
        return slow ;
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
    List LL ;
    LL.insert(1,1);
    LL.insert(2,2);
    LL.insert(3,3);
    LL.insert(4,4);
    LL.insert(5,5);
    LL.display() ;
    Node *mid2 = LL.findMid() ;
    cout << "Middle element for odd list is : " << mid2->data << endl ;

    List ll ;
    ll.insert(1,1);
    ll.insert(2,2);
    ll.insert(3,3);
    ll.insert(4,4);
    ll.insert(5,5);
    ll.insert(6,6);
    ll.display() ;
    Node *mid1 = ll.findMid() ;
    cout << "Middle element for even list is : " << mid1->data << endl ;
}