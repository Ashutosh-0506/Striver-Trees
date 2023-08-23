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
bool IsLeaf(Node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    return false;
}
void AddLeftBoundary(Node *root, vector<int> &ans)
{
    Node *temp = root->left;
    while (temp != NULL)
    {
        if (!IsLeaf(temp))
        {
            ans.push_back(temp->data);
        }

        if (temp->left != NULL)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
}
void AddLeaf(Node *root, vector<int> &ans)
{
    if (IsLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    if (root->left != NULL)
    {
        AddLeaf(root->left, ans);
    }
    if (root->right != NULL)
    {
        AddLeaf(root->right, ans);
    }
}
void AddRightBoundary(Node *root, vector<int> &ans)
{
    Node *temp = root->right;
    stack<int> st;
    while (temp != NULL)
    {
        if (!IsLeaf(temp))
        {
            st.push(temp->data);
        }

        if (temp->left != NULL)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
}
vector<int> Boundary(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    if (!IsLeaf(root))
    {
        ans.push_back(root->data);
    }
    AddLeftBoundary(root, ans);
    AddLeaf(root, ans);
    AddRightBoundary(root, ans);
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
    vector<int> ans = Boundary(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}