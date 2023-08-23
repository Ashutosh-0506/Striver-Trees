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
int MaxWidth(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans=0;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int minn = q.front().second;
        int size = q.size();
        int first, last;
        for (int i = 0; i < size; i++)
        {
            int curr = q.front().second - minn;
            Node *temp = q.front().first;
            q.pop();
            if (i == 0)
            {
                first = curr;
            }
            if (i == size - 1)
            {
                last = curr;
            }
            if (temp->left != NULL)
            {
                q.push({temp->left, ((curr * 2) + 1)});
            }
            if (temp->right != NULL)
            {
                q.push({temp->right, ((curr * 2 )+ 2)});
            }
        }
        ans=max(ans,(last-first+1));
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
    cout<<MaxWidth(root)<<endl;
    return 0;
}