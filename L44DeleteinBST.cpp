//***********************************ASHUTOSH KUMAR***********************************//
/*
कर्मण्येवाधिकारस्ते मा फलेषु कदाचन।
मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि॥

Karmanye vadhikaraste Ma Phaleshu Kadachana,
Ma Karmaphalaheturbhurma Te Sangostvakarmani,

The meaning of the verse is :—
You have the right to work only but never to its fruits.
Let not the fruits of action be your motive, nor let your attachment be to
inaction
*/
#include <bits/stdc++.h>
using namespace ::std;
struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
    Node(int val)
    {
        right = NULL;
        left = NULL;
        data = val;
    }
};
Node* MaxRight(Node* root)
{
    if(root->right==NULL)
    {
        return root;
    }
    return MaxRight(root->right);
}
Node *Helper(Node *root)
{
    if(root->left==NULL)
    {
        return root->right;
    }
    if(root->right==NULL)
    {
        return root->left;
    }
    Node* rightchild=root->right;
    Node* leftChild=MaxRight(root->left);
    leftChild->right=rightchild;
}
Node *Delete(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return Helper(root);
    }
    Node *dummy = root;
    while (root != NULL)
    {
        if (root->data > key)
        {
            if (root->left != NULL && root->left->data == key)
            {
                root->left = Helper(root->left);
            }
            else
            {
                root = root->left;
            }
        }
        else
        {
            if (root->right != NULL && root->right->data == key)
            {
                root->right = Helper(root->right);
            }
            else
            {
                root = root->right;
            }
        }
    }
    return dummy;
}
int main()
{
    struct Node *root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    return 0;
}