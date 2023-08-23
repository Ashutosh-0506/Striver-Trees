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
void ChildrenSum(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    int child = 0;
    if (root->left != NULL)
    {
        child += root->left->data;
    }
    if (root->right != NULL)
    {
        child += root->right->data;
    }
    if (child >= root->data)
    {
        root->data = child;
    }
    else
    {
        if (root->left != NULL)
        {
            root->left->data = root->data;
        }
        if (root->right != NULL)
        {
            root->right->data = root->data;
        }
    }
    ChildrenSum(root->left);
    ChildrenSum(root->right);

    int temp = 0;
    if (root->left != NULL)
    {
        temp += root->left->data;
    }
    if (root->right != NULL)
    {
        temp += root->right->data;
    }
    if(root->left!=NULL || root->right!=NULL)
    {
        root->data=temp;
    }
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    ChildrenSum(root);
    preorder(root);
    return 0;
}