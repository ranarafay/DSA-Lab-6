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
// parameterized
Node ::Node(int x, Node *nxt, Node *prv)
{
    data = x;
    next = nxt;
    prev = prv;
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
    // parameterized
    DoublyLinkedList(int);
};
// inplementation for class DoublyLinked List
// constructors
// default
DoublyLinkedList ::DoublyLinkedList()
{
    Head = NULL;
}
// parameterized
DoublyLinkedList ::DoublyLinkedList(int val)
{
    Node *newnode = new Node;
    newnode->data = val;

    // as list is empty 
    Head = newnode;
}

int main()
{
    DoublyLinkedList l1(15);
    return 0;
}