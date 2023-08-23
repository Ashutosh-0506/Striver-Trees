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
     int val;
     Node*left;
     Node*right;
     Node() : val(0), left(nullptr), right(nullptr) {}
     Node(int x) : val(x), left(nullptr), right(nullptr) {}
     Node(int x, Node*left, Node*right) : val(x), left(left), right(right) {}
 };

 class Solution
 {
     Node*Makeparent(Node*root, unordered_map<Node*, Node*> &Parents, int start)
     {
         queue<Node*> q;
         q.push(root);
         Node*target;
         while (!q.empty())
         {
             Node*temp = q.front();
             if (temp->val == start)
             {
                 target = temp;
             }
             if (temp->left != NULL)
             {
                 Parents[temp->left] = temp;
                 q.push(temp->left);
             }
             if (temp->right != NULL)
             {
                 Parents[temp->right] = temp;
                 q.push(temp->right);
             }
         }
         return target;
     }

 public:
     int amountOfTime(Node*root, int start)
     {
         unordered_map<Node*, bool> Visited;
         unordered_map<Node*, Node*> Parents;
         Node*target = Makeparent(root, Parents, start);
         queue<Node*> q;
         q.push(target);
         int maxx = 0;
         Visited[target] = true;
         while (!q.empty())
         {
             int size = q.size();
             int flag = 0;
             for (int i = 0; i < size; i++)
             {
                 Node*temp = q.front();
                 q.pop();
                 if (temp->left != NULL && !Visited[temp->left])
                 {
                     flag = 1;
                     q.push(temp->left);
                     Visited[temp->left] = 1;
                 }
                 if (temp->right != NULL && !Visited[temp->right])
                 {
                     flag = 1;
                     q.push(temp->right);
                     Visited[temp->right] = 1;
                 }
                 if (Parents[temp] != NULL && !Visited[Parents[temp]])
                 {
                     flag = 1;
                     q.push(Parents[temp]);
                     Visited[Parents[temp]] = 1;
                 }
             }
             if (flag == 1)
             {
                 maxx++;
             }
         }
         return maxx;
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