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
void Right(Node *root, int level, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }
    Right(root->right, level + 1, ans);
    Right(root->left, level + 1, ans);
}
vector<int> RightView(Node *root)
{
    vector<int> ans;

    int level = 0;
    Right(root, level, ans);
    return ans;
}
void Left(Node *root, int level, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }
    Left(root->left, level + 1, ans);
    Left(root->right, level + 1, ans);
}
vector<int> LeftView(Node *root)
{
    vector<int> ans;
    int level = 0;
    Left(root, level, ans);
    return ans;
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
    vector<int> Right, Left;
    Right = RightView(root);
    Left = LeftView(root);
    for (auto it : Right)
    {
        cout << it << " ";
    }
    cout << endl;
    for (auto it : Left)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}