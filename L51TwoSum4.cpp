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
    Node(int data)
    {
        right = NULL;
        left = NULL;
        data = data;
    }
};
class BST
{
public:
    stack<Node *> st;
    // reverse=true->before
    // reverse=false->after/next
    bool reverse = true;

    void PushAll(Node *root)
    {
        while (root != NULL)
        {
            if (reverse)
            {
                st.push(root);
                root = root->right;
            }
            else
            {
                st.push(root);
                root = root->left;
            }
        }
    }
    int next()
    {
        Node *temp = st.top();
        st.pop();
        if (!reverse)
        {
            PushAll(temp->right);
        }
        else
        {
            PushAll(temp->left);
        }

        return temp->data;
    }

    BST(Node *root, bool isreverse)
    {
        reverse = isreverse;
        PushAll(root);
    }
};
class Solution
{

public:
    bool findTarget(Node *root, int k)
    {
        if (root == NULL)
        {
            return false;
        }
        BST *l = new BST(root, false);
        BST *r = new BST(root, true);
        int i = l->next();
        int j = r->next();
        while (j > i)
        {
            if (i + j == k)
            {
                return true;
            }
            if (i + j > k)
            {
                j = r->next();
            }
            else
            {
                i = l->next();
            }
        }
        return false;
    }
};
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