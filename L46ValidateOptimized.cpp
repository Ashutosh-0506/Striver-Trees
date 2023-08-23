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
#include<bits/stdc++.h>
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
bool solve(Node *root, long long minn, long long maxx)
{
    if (root == NULL)
    {
        return true;
    }
    if ((root->data) >= maxx || (root->data <= minn))
    {
        return false;
    }
    return (solve(root->left, minn, root->data) && solve(root->right, root->data, maxx));
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