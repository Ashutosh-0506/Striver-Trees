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
Node *LowestCommonAncestor(Node *root, Node *a, Node *b)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root == a || root == b)
    {
        return root;
    }
    Node *left = LowestCommonAncestor(root->left, a, b);
    Node *right = LowestCommonAncestor(root->right, a, b);
    if (left != NULL && right != NULL)
    {
        return root;
    }
    else if (left != NULL)
    {
        return left;
    }
    else if (right != NULL)
    {
        return right;
    }
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
    cout << LowestCommonAncestor(root, root->left->left, root->left->right)->data;
    return 0;
}