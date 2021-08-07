#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *rightPtr;
    Node *leftPtr;
    Node(int val) {
        data = val;
        rightPtr = nullptr;
        leftPtr = nullptr;
    }
};

class BST {
    public:
    Node *root = NULL;
    Node *insert(Node *root, Node *current) {
        if(root == NULL)
        return current;
        else if(current->data < root->data)
        root->leftPtr = insert(root->leftPtr, current);
        else if(current->data > root->data)
        root->rightPtr = insert(root->rightPtr, current);
        return root;
    }

    Node* min(Node* root) {
        if(root==NULL)
        return root;
        Node* ptr = root;
        while(ptr->leftPtr)
        {
            ptr=ptr->leftPtr;
        }
        return ptr;
    }

    Node* remove(Node*root, int val) {
        if(root==NULL)
        return root;
        else if(root->data > val)
        root->leftPtr = remove(root->leftPtr, val);
        else if(root->data < val)
        root->rightPtr = remove(root->rightPtr, val);
        else
        {
            if(root->leftPtr == NULL)
            {
                Node *temp = root->rightPtr;
                delete(root);
                return temp;
            }
            else if(root->rightPtr == NULL)
            {
                Node *temp = root->leftPtr;
                delete(root);
                return temp;
            }
            Node* ptr = min(root->rightPtr);
            root->data = ptr->data;
            root->rightPtr = remove(root->rightPtr, ptr->data);
        }
        return root;
    }

    void traverseInOrder(Node *root) {
        if(root == NULL)
        return;
        traverseInOrder(root->leftPtr);
        cout<<root->data<<" ";
        traverseInOrder(root->rightPtr);
    }

    void traversePreOrder(Node *root) {
        if(root == NULL)
        return;
        cout<<root->data<<" ";
        traversePreOrder(root->leftPtr);
        traversePreOrder(root->rightPtr);
    }
    
    void traversePostOrder(Node *root) {
        if(root == NULL)
        return;
        traversePostOrder(root->leftPtr);
        traversePostOrder(root->rightPtr);
        cout<<root->data<<" ";
    }
};

int main() {
    BST tree;
    int n=1,i;
    while(n<7)
    {
        cout<<"Enter number: ";
        cin>>i;
        Node *x = new Node(i);
        tree.root = tree.insert(tree.root, x);
        n++;
    }
    tree.traverseInOrder(tree.root);
    cout<<endl;
    tree.traversePreOrder(tree.root);
    cout<<endl;
    tree.traversePostOrder(tree.root);
    cout<<"Enter value to remove: ";
    int val;
    cin>>val;
    tree.remove(tree.root, val);
    cout<<endl;
    tree.traverseInOrder(tree.root);
    cout<<endl;
    tree.traversePreOrder(tree.root);
    cout<<endl;
    tree.traversePostOrder(tree.root);
    return 0;
}