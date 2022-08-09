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
    void InsertAtLast(int);
    void Swap(int, int);
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
void DoublyLinkedList ::Swap(int i1, int i2)
{
    Node *temp1 = Head;
    Node *temp2 = Head;

    int cnt1 = 0;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;

        if (cnt1 == i1)
        {
            break;
        }
        cnt1++;
    }

    int cnt2 = 0;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;

        if (cnt2 == i2)
        {
            break;
        }
        cnt2++;
    }

    Node *left = temp1->prev;
    Node *right = temp2->prev;

    Node *tmp = Head;

    tmp = left->prev;
    if (tmp)
    {
        tmp->next = right;
        right->prev = tmp;
    }
    else
        right->prev = NULL;

    left->prev = right;
    left->next = right->next;
    right->next = left;
    right->next->prev = left->prev;
}

int main()
{
    DoublyLinkedList l1;
    l1.InsertAtLast(10);
    l1.InsertAtLast(20);
    l1.InsertAtLast(30);
    l1.InsertAtLast(40);
    l1.InsertAtLast(50);

    l1.Swap(1, 3);
    l1.Display();
    return 0;
}