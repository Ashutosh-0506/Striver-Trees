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
Node *ConstructTree(vector<int> &inorder, int inStart, int inEnd, vector<int> &preorder, int preStart, int preEnd, unordered_map<int, int> &mp)
{
    if (inStart > inEnd || preStart > preEnd)
    {
        return NULL;
    }
    Node *root = new Node(preorder[preStart]);

    int inroot = mp[root->data];
    int numleft = inroot-inStart;

    root->left = ConstructTree(inorder, inStart, inroot - 1, preorder, preStart + 1, preStart + numleft, mp);
    root->right = ConstructTree(inorder, inroot + 1, inEnd, preorder, preStart + numleft + 1, preEnd, mp);
    return root;
}
Node *BuildTree(vector<int> &inorder, vector<int> &preorder)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }
    int inStart = 0;
    int inEnd = inorder.size() - 1;
    int preStart = 0;
    int preEnd = preorder.size() - 1;

    Node *root = ConstructTree(inorder, inStart, inEnd, preorder, preStart, preEnd, mp);
    return root;
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
    return 0;
}