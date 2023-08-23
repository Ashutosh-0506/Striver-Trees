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
class NodeValue
{
public:
    int maxx;
    int minn;
    int maxsize;
    int maxsum;

    NodeValue(int maxx, int minn, int maxsum)
    {
        this->maxx = maxx;
        this->minn = minn;
        this->maxsum = maxsum;
    }
};
class Solution
{
    int sum = 0;
private:
    NodeValue LargestBST(Node *root)
    {
        if (root == NULL)
        {
            return NodeValue(INT_MIN, INT_MAX, 0);
        }

        auto l = LargestBST(root->left);
        auto r = LargestBST(root->right);

        if (l.maxx < root->data && r.minn > root->data)
        {
            sum=max(sum,(root->data + r.maxsum + l.maxsum));
            return NodeValue(max(root->data, r.maxx), min(root->data, l.minn), (root->data + r.maxsum + l.maxsum));
        }

        return NodeValue(INT_MAX, INT_MIN, max(l.maxsum, r.maxsum));
    }

public:
    int maxSumBST(Node *root)
    {
        LargestBST(root);
        return sum>0?sum:0;
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