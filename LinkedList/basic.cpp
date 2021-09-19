#include <bits/stdc++.h>
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

Node *insertLast(Node *head, int val)
{
    Node *temp = head;

    if (!temp)
    {
        head = new Node(val);
        return head;
    }
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = new Node(val);
    return head;
}

Node *insertStart(Node *head, int val)
{
    if (!head)
    {
        head = new Node(val);
        return head;
    }

    Node *temp = head;
    Node *ptr = new Node(val);
    ptr->next = temp;
    head = ptr;
    return head;
}

void search(Node *head, int val)
{
    Node *temp = head;
    int count = 0;
    bool flag = false;

    while (temp)
    {
        count++;
        if (temp->data == val)
        {
            flag = true;
            break;
        }
        temp = temp->next;
    }
    if (!flag)
    {
        cout << val << " not found in LinkedList.\n";
    }
    else
    {
        cout << val << " found at position " << count << " in LinkedList!\n";
    }
}

Node *deleteNode(Node *head, int val)
{
    if (head->data == val)
    {
        Node *ptr = head;
        if (head->next)
            head = head->next;
        else
            head = NULL;
        return head;
    }

    Node *temp = head;
    while (temp->next->data != val && temp)
    {
        temp = temp->next;
    }
    if (temp)
    {
        Node *ptr = temp->next;
        temp->next = temp->next->next;
        delete ptr;
    }
    return head;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main()
{

    Node *head = NULL;

    head = insertLast(head, 1);
    head = insertLast(head, 2);
    head = insertLast(head, 3);
    display(head);
    search(head, 2);
    head = insertStart(head, 0);
    display(head);
    search(head, 0);
    head = deleteNode(head, 2);
    display(head);
    return 0;
}