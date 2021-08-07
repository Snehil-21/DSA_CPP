#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BT
{
public:
    Node *insert(Node *root, Node *ptr)
    {
        if (root == NULL)
        {
            root = ptr;
            return root;
        }
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left != NULL)
                q.push(temp->left);
            else
            {
                temp->left = ptr;
                return root;
            }
            if (temp->right != NULL)
                q.push(temp->right);
            else
            {
                temp->right = ptr;
                return root;
            }
        }
        return root;
    }

    void inorder(Node *root)
    {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main()
{
    BT tree;
    int n;
    Node *root = NULL;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    while (n--)
    {
        int x;
        cin >> x;
        Node *ptr = new Node(x);
        root = tree.insert(root, ptr);
    }
    tree.inorder(root);
    cout << "Enter number to be inserted: ";
    int x;
    cin >> x;
    Node *ptr = new Node(x);
    root = tree.insert(root, ptr);
    tree.inorder(root);
    return 0;
}