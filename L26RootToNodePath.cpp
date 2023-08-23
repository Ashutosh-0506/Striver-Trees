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
bool GetPath(Node *root, vector<int> &ans, int x)
{
    if (root == NULL)
    {
        return false;
    }
    ans.push_back(root->data);

    if(root->data==x)
    {
        return true;
    }

    if (GetPath(root->left, ans, x) || GetPath(root->right, ans, x))
    {
        return true;
    }

    ans.pop_back();
    return false;
}
vector<int> RootToNodePath(Node* root,int B)
{
    vector<int>ans;
    if(root==NULL)
    {
        return ans;
    }
    GetPath(root,ans,B);
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
    int B;
    cin>>B;
    vector<int>ans=RootToNodePath(root,B);
    for(auto it: ans)
    {
        cout<<it<<" ";
    }
    return 0;
}