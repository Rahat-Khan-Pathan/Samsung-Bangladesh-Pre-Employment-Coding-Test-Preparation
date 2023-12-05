// This is not for pre-employment test
// https://www.geeksforgeeks.org/convert-a-given-tree-to-sum-tree/
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
};
int toSumTree(Node *node)
{
    // Your code here
    if (node == NULL)
        return 0;
    if (node->left == NULL && node->right == NULL)
    {
        int prev = node->data;
        node->data = 0;
        return prev;
    }
    int prev = node->data;
    int nw = (toSumTree(node->left) + toSumTree(node->right));
    node->data = nw;
    return prev + nw;
}
int main()
{

    return 0;
}