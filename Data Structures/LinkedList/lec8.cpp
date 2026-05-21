// Circular LinkedList

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
public:
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    void insert(int val, int pos)
    {
        Node *newNode = new Node(val);
        if (pos < 1)
        {
            cout << "Invalid Position";
            return;
        }
        if (pos == 1)
        {
            if (head == NULL)
            {
                head = tail = newNode;
                tail->next = head;
            }
            else
            {
                newNode->next = head;
                head = newNode;
                tail->next = head;
                return;
            }
        }
        Node *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (temp == tail)
        {
            tail = newNode;
        }
        return;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "head " << endl;
    }
};

int main(){
    List ll ;
    ll.insert(1,1) ;
    ll.insert(2,2) ;
    ll.insert(3,3) ;
    ll.insert(4,4) ;
    ll.insert(5,5) ;
    ll.insert(6,6) ;
    ll.display() ;

}