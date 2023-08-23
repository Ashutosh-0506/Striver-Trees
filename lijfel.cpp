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
struct TreeNode
{
    int val;
    struct TreeNode *right;
    struct TreeNode *left;
    TreeNode(int val)
    {
        right = NULL;
        left = NULL;
        val = val;
    }
};
class Solution
{
private:
    TreeNode *first;
    TreeNode *middle;
    TreeNode *last;
    TreeNode *prev;
    void inorder(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);

        if (prev != NULL && root->val < prev->val)
        {
            if (first == NULL)
            {
                first = prev;
                middle = root;
            }
            else
            {
                last = root;
            }
        }

        prev = root;
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode *root)
    {
        first = NULL;
        middle = NULL;
        last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if (first && last)
        {
            swap(first->val, last->val);
        }
        else if (first && middle)
        {
            swap(first->val, middle->val);
        }
    }
};
int main()
{
    struct TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    return 0;
}