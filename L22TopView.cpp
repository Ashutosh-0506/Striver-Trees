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
vector<int> Topview(Node* root)
{
    vector<int>ans;
    if(root==NULL)
    {
        return ans;
    }
    queue<pair<Node* ,int>>q;
    map<int,int>mp;
    q.push({root,0});
    while(!q.empty())
    {
        auto it =q.front();
        q.pop();
        Node* temp=it.first;
        int x=it.second;
        if(temp->left!=NULL)
        {
            q.push({temp->left,x-1});
        }
        if(temp->right!=NULL)
        {
            q.push({temp->right,x+1});
        }
        if(mp.find(x)==mp.end())
        {
            mp[x]=temp->data;
        }

    }
    for(auto it:mp)
    {
        ans.push_back(it.second);
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
    vector<int>ans=Topview(root);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    return 0;
}