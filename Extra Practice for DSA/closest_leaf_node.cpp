// This is not for pre-employment test
// https://www.geeksforgeeks.org/closest-leaf-to-a-given-node-in-binary-tree/
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int v)
    {
        val = v;
        left = NULL;
        right = NULL;
    }
};
void view(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();
        cout << p->val << endl;
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
}
int findNode(Node *root, Node *fn)
{
    if (root == NULL)
        return INT_MAX;
    if (root == fn)
        return 0;
    int a = findNode(root->left, fn);
    int b = findNode(root->right, fn);
    if (a == INT_MAX && b == INT_MAX)
        return a;
    return min(a, b) + 1;
}
int findLeaf(Node *root)
{
    if (root == NULL)
        return INT_MAX;
    if (root->left == NULL && root->right == NULL)
        return 0;
    return min(findLeaf(root->left), findLeaf(root->right)) + 1;
}
int fnd(Node *root, Node *fn)
{
    if (root == NULL)
        return INT_MAX;

    int a = findNode(root->right, fn);
    int b = findNode(root->left, fn);
    int ans = INT_MAX;
    if (a != INT_MAX)
    {
        int x = findLeaf(root->left);
        if (x != INT_MAX)
            ans = min(ans, x + a + 2);
    }
    else if (b != INT_MAX)
    {
        int x = findLeaf(root->right);
        if (x != INT_MAX)
            ans = min(ans, x + b + 2);
    }
    else
    {
        return INT_MAX;
    }
    return min({ans, fnd(root->left, fn), fnd(root->right, fn)});
}
void solve()
{
    int n;
    cin >> n;
    Node *root = new Node(n);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();
        int l, r;
        cin >> l >> r;
        Node *left = NULL;
        Node *right = NULL;
        if (l != -1)
            left = new Node(l);
        if (r != -1)
            right = new Node(r);
        p->left = left;
        p->right = right;
        if (left)
            q.push(left);
        if (right)
            q.push(right);
    }
    Node *fn = root->right->left->left;
    cout << min(fnd(root, fn), findLeaf(fn));
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
