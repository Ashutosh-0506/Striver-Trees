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
/**
 * Definition for a binary tree node.
 * struct Node {
 *     int data;
 *     Node *left;
 *     Node *right;
 *     Node() : data(0), left(nullptr), right(nullptr) {}
 *     Node(int x) : data(x), left(nullptr), right(nullptr) {}
 *     Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
 * };
 */

    Node* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        if(n==0)
        {
            return NULL;
        }
        Node* root=new Node(preorder[0]);
        for(int i=1;i<n;i++)
        {
            int data=preorder[i];
            Node* curr=root;
            Node* prev=NULL;
            while(curr!=NULL)
            {
                if(data>curr->data)
                {
                    prev=curr;
                    curr=curr->right; 
                }
                else
                {
                    prev=curr;
                    curr=curr->left;
                }
            }
            Node* temp=new Node(data);
            if(prev->data>data)
            {
                prev->left=temp;
            }
            else
            {
                prev->right=temp;
            }
        }
        return root;
    }

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