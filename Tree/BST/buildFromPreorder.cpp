#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *buildFromPreorder(int preorder[], int *preIdx, int key, int min, int max, int n)
{
    if (*preIdx > n)
    {
        return NULL;
    }

    Node *root = NULL;
    if (key > min && key < max)
    {
        root = new Node(key);

        *preIdx = *preIdx + 1;
        if (*preIdx < n)
        {
            root->left = buildFromPreorder(preorder, preIdx, preorder[*preIdx], min, key, n);
        }
        if (*preIdx < n)
        {
            root->right = buildFromPreorder(preorder, preIdx, preorder[*preIdx], key, max, n);
        }
    }
    return root;
}

void preOrder(Node *root)
{
    if (!root)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{

    int preorder[] = {10, 2, 1, 13, 11};
    int n = 5;
    int preIdx = 0;
    Node *root = buildFromPreorder(preorder, &preIdx, preorder[0], INT_MIN, INT_MAX, 5);

    preOrder(root);

    return 0;
}