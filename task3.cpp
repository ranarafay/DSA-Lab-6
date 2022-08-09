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
            if (temp->prev == NULL)
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
            // last Node
            else if (temp->next == NULL)
            {
                Node *temp = Head;
                Head = temp->next;
                Head->prev = NULL;

                delete temp;
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
void DoublyLinkedList ::RemoveDuplicates()
{
    Node *temp = Head;
    int ind = 0;
    while (temp->next != NULL)
    {
        Node *temp1 = temp;
        while (temp1->next != NULL)
        {
            if (temp->data == temp1->data)
            {
                DeleteAt(ind);
            }
            temp1 = temp1->next;
        }
        temp = temp->next;
        ind++;
    }
}
int main()
{
    DoublyLinkedList l1;
    l1.InsertAtLast(10);
    l1.InsertAtLast(20);
    l1.InsertAtLast(5);
    l1.InsertAtLast(5);
    l1.Display();
    l1.RemoveDuplicates();
    cout << endl;
    l1.Display();
    return 0;
}