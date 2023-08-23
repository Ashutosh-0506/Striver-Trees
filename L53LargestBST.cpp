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
class NodeValue
{
public:
    int maxx;
    int minn;
    int maxsize;

    NodeValue(int maxx, int minn, int maxsize)
    {
        this->maxx = maxx;
        this->minn = minn;
        this->maxsize = maxsize;
    }
};
class solution
{
private:
    NodeValue LargestBST(Node* root)
    {
        if(root==NULL)
        {
            return NodeValue(INT_MIN,INT_MAX,0);
        }
        
        auto l=LargestBST(root->left);
        auto r=LargestBST(root->right);

        if(l.maxx<root->data && r.minn >root->data)
        {
            return NodeValue(max(root->data,r.maxx),min(root->data,l.minn),(1+l.maxsize+r.maxsize));
        }

        return NodeValue(INT_MAX,INT_MIN,max(l.maxsize,r.maxsize));
    }
    public:
    int largestBSTSubTree(Node* root)
    {
        return LargestBST(root).maxsize;
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