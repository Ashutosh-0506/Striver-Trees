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

void inorder(Node *root, int &ans, int &index, int k)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, ans, index, k);
    index++;
    if (index == k)
    {
        ans = root->data;
    }
    inorder(root->right, ans, index, k);
}

int kthSmallest(Node *root, int k)
{
    vector<int> v;
    int index = 0;
    int ans = 0;
    inorder(root, ans, index, k);
    return ans;
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