// Flatten the linkedlist

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node *child;

    Node(int val)
    {
        data = val;
        next = prev = child = NULL;
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
            cout << "Invalid Position\n";
            return;
        }

        if (pos == 1)
        {
            if (head == NULL)
            {
                head = tail = newNode;
                return;
            }
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }

        Node *temp = head;

        for (int i = 1; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Invalid Position\n";
                return;
            }
            temp = temp->next;
        }

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }

        temp->next = newNode;

        if (newNode->next == NULL)
        {
            tail = newNode;
        }
    }

    void display()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    Node *flatten(Node *head)
    {

        if (head == NULL)
            return head;

        Node *curr = head;

        while (curr != NULL)
        {

            if (curr->child != NULL)
            {

                Node *next = curr->next;

                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;

                while (curr->next != NULL)
                {
                    curr = curr->next;
                }

                if (next != NULL)
                {
                    curr->next = next;
                    next->prev = curr;
                }
            }

            curr = curr->next;
        }

        return head;
    }

    void flattenList()
    {
        head = flatten(head);
    }
};

int main()
{

    List ll;

    ll.insert(1, 1);
    ll.insert(2, 2);
    ll.insert(3, 3);
    ll.insert(4, 4);
    ll.insert(5, 5);

    // create child list
    Node *child1 = new Node(7);
    Node *child2 = new Node(8);
    Node *child3 = new Node(9);

    child1->next = child2;
    child2->prev = child1;

    child2->next = child3;
    child3->prev = child2;

    // attach child list to node 3
    Node *temp = ll.head;
    while (temp->data != 3)
    {
        temp = temp->next;
    }

    temp->child = child1;

    cout << "Original List:\n";
    ll.display();

    ll.flattenList();

    cout << "\nFlattened List:\n";
    ll.display();
}