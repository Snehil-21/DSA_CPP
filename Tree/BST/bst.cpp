#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }

    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }

    else
    {
        root->right = insert(root->right, val);
    }

    return root;
}

bool search(Node *root, int val)
{
    if (!root)
    {
        return false;
    }

    if (root->data == val)
        return true;

    if (root->data > val)
        return search(root->left, val);

    return search(root->right, val);
}

Node *findInorderSuccessor(Node *root)
{
    while (root->left)
    {
        root = root->left;
    }
    return root;
}

Node *remove(Node *root, int key)
{
    if (root->data > key)
    {
        root->left = remove(root->left, key);
    }
    else if (root->data < key)
    {
        root->right = remove(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            Node *temp = findInorderSuccessor(root->right);
            root->data = temp->data;
            root->right = remove(root->right, temp->data);
        }
    }
    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{

    int a[] = {5, 2, 1, 3, 4, 6};
    int len = sizeof(a) / sizeof(a[0]);

    Node *root = NULL;
    root = insert(root, a[0]);

    for (int i = 1; i < len; i++)
    {
        insert(root, a[i]);
    }

    // inorder(root);
    // cout << endl;
    // cout << search(root, 7);
    // cout << endl;
    // remove(root, 3);
    inorder(root);

    return 0;
}