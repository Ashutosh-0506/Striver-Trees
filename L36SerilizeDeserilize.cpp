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
/**
 * Definition for a binary tree node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(Node *root)
    {
        string st = "";
        if (root == NULL)
        {
            return st;
        }
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                st.push_back('#');
                st.push_back(',');
            }
            else
            {
                st+=(temp->data);
                st+=',';
            }

            if (temp != NULL)
            {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return st;
    }

    // Decodes your encoded data to tree.
    Node *deserialize(string data)
    {
        if (data.size() == 0)
        {
            return NULL;
        }
        stringstream s(data);
        string str;
        getline(s, str, ',');
        Node *root = new Node(stoi(str));
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            getline(s, str, ',');
            if (str == "#")
            {
                temp->left = NULL;
            }
            else
            {
                Node *nodeleft = new Node(stoi(str));
                temp->left = nodeleft;
                q.push(nodeleft);
            }

            if (str == "#")
            {
                temp->right = NULL;
            }
            else
            {
                Node *noderight = new Node(stoi(str));
                temp->right = noderight;
                q.push(noderight);
            }
        }
        return root;
    }
};

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