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
void MakeParent(Node *root, unordered_map<Node *, Node *> &Parent)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if (curr->left != NULL)
        {
            q.push(curr->left);
            Parent[curr->left] = curr;
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
            Parent[curr->right] = curr;
        }
    }
}
vector<int> DistanceK(Node *root, Node *target, int K)
{
    unordered_map<Node *, Node *> Parent;
    MakeParent(root, Parent);
    unordered_map<Node *, bool> Visited;
    queue<Node *> q;
    q.push(root);
    int curr = 0;
    while (!q.empty())
    {
        int size = q.size();
        if (curr++ == K)
        {
            break;
        }
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left != NULL && !Visited[temp->left])
            {
                q.push(temp->left);
                Visited[temp->left] = true;
            }
            if (temp->right != NULL && !Visited[temp->right])
            {
                q.push(temp->right);
                Visited[temp->right] = true;
            }
            if (Parent[temp] != NULL && !Visited[Parent[temp]])
            {
                q.push(Parent[temp]);
                Visited[Parent[temp]] = true;
            }
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        ans.push_back(curr->data);
    }
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
    return 0;
}