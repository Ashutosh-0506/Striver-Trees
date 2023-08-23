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
vector<vector<int>> VerticalOrderTraversal(Node *root)
{
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<Node *, pair<int, int>>> todo;
    todo.push({root, {0, 0}});
    while (!todo.empty())
    {
        auto p = todo.front();
        todo.pop();
        Node *temp = p.first;

        int x = p.second.first;
        int y = p.second.second;

        nodes[x][y].insert(temp->data);
        if (temp->left != NULL)
        {
            todo.push({temp->left, {x - 1, y + 1}});
        }
        if (temp->right != NULL)
        {
            todo.push({temp->right, {x + 1, y + 1}});
        }
    }

    vector<vector<int>> ans;
    for (auto it : nodes)
    {
        vector<int>col;
        for(auto i:it.second)
        {
            col.insert(col.end(),i.second.begin(),i.second.end());
        }
        ans.push_back(col);
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
    vector<vector<int>>ans=VerticalOrderTraversal(root);
    for(auto i:ans)
    {
        for(auto it:i)
        {
            cout<<it<<" ";
        }
      
    }
    return 0;
}