#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int n)
    {
        data = n;
        next = NULL;
    }
};

class LinkedList
{
    Node *head = NULL;

public:
    void insert(int x)
    {
        Node *ptr = new Node(x);
        Node *temp = head;
        if (!head)
        {
            head = ptr;
            return;
        }
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = ptr;
    }

    void remove(int x)
    {
        Node *temp = head;
        Node *ptr = head;
        if (!head)
        {
            return;
        }
        if (head->data == x)
        {
            head = head->next;
        }
        while (temp->next && temp->data != x)
        {
            ptr = temp;
            temp = temp->next;
        }
        if (temp->data == x && temp->next == NULL)
        {
            ptr->next = NULL;
            return;
        }
        else if (temp->data == x)
        {
            ptr->next = temp->next;
            delete (temp);
            return;
        }
        if (temp)
        {
            delete (ptr->next);
            ptr->next = temp;
        }
    }

    void search(int x)
    {
        Node *temp = head;
        int pos = 0;

        while (temp)
        {
            if (temp->data == x)
            {
                cout << "Element found in linked list at: " << pos << endl;
                break;
            }
            temp = temp->next;
            pos++;
        }
        if (!temp)
            cout << "Element not found in linked list!\n";
    }

    void showList()
    {
        Node *temp = head;
        while (temp->next)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << temp->data << " -> NULL" << endl;
    }
};

int main()
{
    LinkedList l;
    l.insert(2);
    l.insert(3);
    l.insert(4);
    // l.remove(6);
    l.search(4);
    l.showList();
    return 0;
}