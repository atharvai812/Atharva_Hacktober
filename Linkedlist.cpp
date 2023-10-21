#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void InsertAtHead(Node *&head, int d)
{

    // new node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node *&tail, int d)
{
    // new tail create
    Node *temp = new Node(d);
    tail->next = temp;
    // tail = tail -> next;
    tail = temp;
}

void InsertAPosition(Node *&tail, Node *&head, int position, int d)
{
    // Insert at start
    if (position == 1)
    {
        InsertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // Inserting at last position
    if (temp->next == NULL)
    {
        InsertAtTail(tail, d);
        return;
    }

    // creating a node for d
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// How to traverse a Linked list
void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Created a new node
    Node *node1 = new Node(10);
    // cout<< node1 -> data <<endl;
    // cout<< node1 -> next <<endl;

    // head pointed to node1
    Node *head = node1;

    // tail pointed to node1
    Node *tail = node1;
    print(head);

    // InsertAtHead(head, 12);
    InsertAtTail(tail, 12);
    print(head);

    // InsertAtHead(head, 15);
    InsertAtTail(tail, 15);
    print(head);

    InsertAPosition(tail, head, 4, 22);
    print(head);

    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    return 0;
}
