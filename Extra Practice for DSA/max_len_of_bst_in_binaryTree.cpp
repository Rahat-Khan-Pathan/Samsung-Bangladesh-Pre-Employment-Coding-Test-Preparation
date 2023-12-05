// This is not for pre-employment test

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
struct Box
{
    int min, max, ans, finalAns;
    bool bst;
    Box(int mn, int mx, int a, bool b, int f)
    {
        min = mn;
        max = mx;
        ans = a;
        bst = b;
        finalAns = f;
    }
    Box() {}
};
class Solution
{
public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    Box solve(Node *root)
    {
        if (root == NULL)
            return Box(INT_MAX, INT_MIN, 0, true, 0);
        if (root->left == NULL && root->right == NULL)
        {
            return Box(root->data, root->data, 1, true, 1);
        }
        Box l = solve(root->left);
        Box r = solve(root->right);
        int ans = (l.ans + r.ans);
        Box b;
        b.min = min({l.min, r.min, root->data});
        b.max = max({l.max, r.max, root->data});
        b.ans = 1;
        b.bst = false;
        if (l.bst && r.bst)
        {
            if (l.max < root->data && r.min > root->data)
            {
                b.ans += ans;
                b.bst = true;
            }
        }
        b.finalAns = max({b.ans, l.finalAns, r.finalAns});
        return b;
    }
    int largestBst(Node *root)
    {
        // Your code here
        return solve(root).finalAns;
    }
};