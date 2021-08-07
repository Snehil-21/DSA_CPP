#include <iostream>
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
        left = right = NULL;
    }
};

class BST
{
public:
    // INSERT NODE IN THE TREE

    Node *insert(int val, Node *root)
    {
        if (!root)
        {
            return root = new Node(val);
        }

        if (root->data > val)
        {
            root->left = insert(val, root->left);
        }
        else
        {
            root->right = insert(val, root->right);
        }
        return root;
    }

    // SEARCH FOR A NODE IN THE TREE

    void search(int val, Node *root)
    {
        while (root)
        {
            if (root->data == val)
            {
                cout << val << " found in the tree!" << endl;
                return;
            }
            else if (root->data > val)
            {
                root = root->left;
            }
            else if (root->data < val)
            {
                root = root->right;
            }
        }
        cout << val << " not found in the tree.";
    }

    // TRAVERSE THE TREE IN INORDER

    void inorder(Node *root)
    {
        if (!root)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main()
{
    BST b;
    Node *root = NULL;
    root = b.insert(5, root);
    b.insert(4, root);
    b.insert(3, root);
    b.insert(6, root);
    b.inorder(root);
    cout << endl;
    // b.search(4, root);
    return 0;
}