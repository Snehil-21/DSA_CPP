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

    // FIND SUCCESSOR OF NODE IN TREE
    Node *minSuccessor(Node *root)
    {
        while (root && root->left)
        {
            root = root->left;
        }
        return root;
    }

    // DELETE A NODE
    Node *deleteNode(int val, Node *root)
    {
        if (!root)
        {
            return NULL;
        }
        if (root->data == val)
        {
            if (!root->left && !root->right)
            {
                delete (root);
                return NULL;
            }
            else if (root->left && !root->right)
            {
                root->data = root->left->data;
                root->left = NULL;
                delete (root->left);
                return root;
            }
            else if (!root->left && root->right)
            {
                root->data = root->right->data;
                root->right = NULL;
                delete (root->right);
                return root;
            }
            else
            {
                Node *x = minSuccessor(root->right);
                root->data = x->data;
                root->right = deleteNode(x->data, root->right);
            }
        }
        else if (root->data > val)
        {
            root->left = deleteNode(val, root->left);
        }
        else if (root->data < val)
        {
            root->right = deleteNode(val, root->right);
        }
        return root;
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
    root = b.insert(10, root);
    b.insert(5, root);
    b.insert(15, root);
    b.insert(4, root);
    b.insert(6, root);
    b.insert(14, root);
    b.insert(16, root);
    b.inorder(root);
    cout << endl;
    b.deleteNode(15, root);
    cout << endl;
    b.inorder(root);
    // b.search(4, root);
    return 0;
}