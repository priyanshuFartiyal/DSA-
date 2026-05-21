// Merge Two Lists

#include<iostream>
using namespace std ;

class Node{
    public :
    int data ;
    Node* next ;
    Node(int val){
        data = val;
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
        Node *newNode = new Node(val) ;
        if(pos < 1 ){
            cout << "invalid position" ;
            return ;
        }
        if(pos == 1){
            if(head == NULL){
                head = tail = newNode ;
                return ;
            }
            newNode->next = head ;
            head = newNode ;
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
        if(temp->next == NULL){
            tail = newNode;
        }
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

Node* mergeList(Node*head1 , Node*head2){
    if(head1==NULL || head2==NULL){
        return head1==NULL ? head2 : head1 ;
    }

    if(head1 < head2){
        head1->next = mergeList(head1->next , head2) ;
        return head1 ;
    }else{
        head2->next = mergeList(head1 , head2->next) ;
        return head2 ;
    }
}

int main(){
    List l1 ;
    l1.insert(1,1) ;
    l1.insert(3,2) ;
    l1.insert(5,3) ;
    l1.display() ;
    List l2 ;
    l2.insert(2,1) ;
    l2.insert(4,2) ;
    l2.insert(6,3) ;
    l2.display() ;

    cout << "Final Merged List :" << endl ;
    Node *head = mergeList(l1.head ,l2.head) ;
    
    Node *temp = head ;
    while(temp != NULL){
        cout << temp->data << "->" ;
        temp = temp->next ;
    }cout << "NULL" << endl ;

}