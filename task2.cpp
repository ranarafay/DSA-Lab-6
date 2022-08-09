#include <iostream>
using namespace std;

// class node for doubly LinkedList
class Node
{
public:
    // data members
    int data;
    Node *next;
    Node *prev;

    // constructors
    // default
    Node();
    // parameterized
    Node(int, Node *, Node *);
};
// inplementation for class Node
// consructors
// default
Node ::Node()
{
    data = 0;
    next = NULL;
    prev = NULL;
}

// class fro Doubly LinkedList
class DoublyLinkedList
{
public:
    // data members
    Node *Head;

    // constructors
    // default
    DoublyLinkedList();

    // functions
    void Display();
    void InsertAtFirst(int);
    void InsertAtLast(int);
    void InsertAt(int, int);
    void DeleteAtFirst();
    void DeleteAtLast();
    void DeleteAt(int);
    void RemoveDuplicates();
};
// inplementation for class DoublyLinked List
// constructors
// default
DoublyLinkedList ::DoublyLinkedList()
{
    Head = NULL;
}
// functions
void DoublyLinkedList ::Display()
{
    // empty list
    if (Head == NULL)
    {
        cout << "List is Empty!" << endl;
    }

    else
    {
        Node *temp = Head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}
void DoublyLinkedList ::InsertAtFirst(int val)
{
    Node *newnode = new Node;
    newnode->data = val;

    // list is empty
    if (Head == NULL)
    {
        Head = newnode;
    }

    // list is not empty
    else
    {
        newnode->next = Head;
        Head->prev = newnode;
        Head = newnode;
    }
}
void DoublyLinkedList ::InsertAtLast(int val)
{
    Node *newnode = new Node;
    newnode->data = val;

    // list is empty
    if (Head == NULL)
    {
        Head = newnode;
    }

    // list is not empty
    else
    {
        Node *temp = Head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->prev = temp;
    }
}
void DoublyLinkedList ::InsertAt(int ind, int val)
{

    // list is empty
    if (Head == NULL)
    {
        cout << "List is Empty!" << endl;
    }

    // list is not empty
    else
    {
        Node *temp = Head;
        int cnt = 0;
        while (temp->next != NULL)
        {
            temp = temp->next;

            if (cnt == ind)
            {
                break;
            }
            cnt++;
        }

        if (cnt == ind)
        {
            Node *newnode = new Node;
            newnode->data = val;

            temp->next = newnode;
            newnode->prev = temp;
        }
    }
}
void DoublyLinkedList ::DeleteAtFirst()
{
    // list is Empty
    if (Head == NULL)
    {
        cout << "List is Already Empty! " << endl;
    }

    else
    {
        Node *temp = Head;
        Head = temp->next;
        Head->prev = NULL;

        delete temp;
    }
}
void DoublyLinkedList ::DeleteAtLast()
{
    // list is Empty
    if (Head == NULL)
    {
        cout << "List is Already Empty! " << endl;
    }

    else
    {
        Node *temp = Head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        Node *prev;
        prev = temp->prev;

        prev->next = NULL;

        delete temp;
    }
}
void DoublyLinkedList ::DeleteAt(int ind)
{

    // list is empty
    if (Head == NULL)
    {
        cout << "List is Empty!" << endl;
    }

    // list is not empty
    else
    {
        Node *temp = Head;
        int cnt = 1;
        while (temp->next != NULL)
        {
            temp = temp->next;

            if (cnt == ind)
            {
                break;
            }
            cnt++;
        }

        if (cnt == ind)
        {
            // first Node
            if (ind == 0)
            {
                DeleteAtFirst();
            }
            // last Node
            else if (temp->next == NULL)
            {
                DeleteAtLast();
            }

            // Inbetween
            else
            {
                Node *prev;
                prev = temp->prev;
                Node *next;
                next = temp->next;

                prev->next = next;
                next->prev = prev;

                delete temp;
            }
        }
    }
}
int main()
{
    DoublyLinkedList l1;
    l1.InsertAtLast(10);
    l1.InsertAtLast(20);
    l1.InsertAtLast(30);
    l1.InsertAtLast(40);
    l1.InsertAtLast(50);

    l1.Display();
    cout << endl;
    l1.DeleteAt(2);
    l1.Display();
    return 0;
}