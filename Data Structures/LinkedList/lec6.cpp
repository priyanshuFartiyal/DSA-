// Copy Linked List with Random Pointer

#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;
    Node(int val)
    {
        data = val;
        next = NULL;
        random = NULL;
    }
};

class List
{
public:
    Node *head;
    Node *tail;

    List()
    {
        head = tail = NULL;
    }
    void insert(int val, int pos)
    {
        Node *newNode = new Node(val);
        if (pos < 1)
        {
            cout << "Invalid Position" << endl;
            return;
        }
        if (pos == 1)
        {
            if (head == NULL)
            {
                head = tail = newNode;
                return;
            }
            else
            {
                newNode->next = head;
                head = newNode;
                return;
            }
        }
        Node *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Invalid Position " << endl;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == NULL)
        {
            tail = newNode;
            return;
        }
        return;
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

Node *copywithRandom(Node *oldhead)
{

    unordered_map<Node *, Node *> m;

    Node *newhead = new Node(oldhead->data);
    Node *oldTemp = oldhead->next;
    Node *newTemp = newhead;

    m[oldhead] = newTemp;

    while (oldTemp != NULL)
    {
        Node *newNode = new Node(oldTemp->data);
        m[oldTemp] = newNode;
        newTemp->next = newNode;
        oldTemp = oldTemp->next;
        newTemp = newNode;
    }

    oldTemp = oldhead;
    newTemp = newhead;
    while (oldTemp != NULL)
    {
        if (oldTemp->random)
        { // Non empty and connected to some other node through random pointer.
            newTemp->random = m[oldTemp->random];
        }
        else
        {
            newTemp->random = NULL;
        }
        oldTemp = oldTemp->next;
        newTemp = newTemp->next;
    }

    return newhead;
}

int main()
{

    List ll;
    ll.insert(7, 1);
    ll.insert(13, 2);
    ll.insert(11, 3);
    ll.insert(10, 4);
    ll.insert(1, 5);
    ll.display();

    // Assign random pointers manually
    ll.head->random = ll.head->next->next;             // 7 → 11
    ll.head->next->random = ll.head;                   // 13 → 7
    ll.head->next->next->random = ll.tail;             // 11 → 1
    ll.head->next->next->next->random = ll.head->next; // 10 → 13
    ll.tail->random = ll.head->next->next;             // 1 → 11

    Node *newhead = copywithRandom(ll.head);
    cout << "Copied list with randoms: ";
    Node *temp = newhead;
    while (temp != NULL)
    {
        cout << temp->data;
        if (temp->random)
            cout << "(random->" << temp->random->data << ")";
        else
            cout << "(random->NULL)";
        cout << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}