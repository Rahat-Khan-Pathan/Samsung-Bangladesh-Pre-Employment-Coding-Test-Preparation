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
void solve(string &s, Node *&root)
{
    // cout << s << endl;
    s.erase(s.begin());
    s.pop_back();
    if (s.size() == 0)
        return;
    int ans = 0;
    int i;
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            break;
        ans *= 10;
        ans += (s[i] - '0');
    }
    root = new Node(ans);
    stack<char> st;
    string leftSide, rightSide;
    int j;
    for (j = i; j < s.size(); j++)
    {
        leftSide += s[j];
        if (s[j] == '(')
            st.push(s[j]);
        if (s[j] == ')')
            st.pop();
        if (st.empty())
            break;
    }
    for (int k = j + 1; k < s.size(); k++)
    {
        rightSide += s[k];
        if (s[k] == '(')
            st.push(s[k]);
        if (s[k] == ')')
            st.pop();
        if (st.empty())
            break;
    }
    solve(leftSide, root->left);
    solve(rightSide, root->right);
}
int ans(Node *root, int k)
{
    int s = 0;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        pair<Node *, int> p = q.front();
        q.pop();
        if (p.second == k)
            s += p.first->val;
        if (p.first->left)
            q.push({p.first->left, p.second + 1});
        if (p.first->right)
            q.push({p.first->right, p.second + 1});
    }
    return s;
}
int main()
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    Node *root;
    solve(s, root);
    // cout << "hello" << endl;
    cout << ans(root, k) << endl;
    return 0;
}