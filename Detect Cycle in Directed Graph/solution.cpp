#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 5;
vector<int> v[mx];
bool vis[mx];
vector<int> ansV;
int ans;
int sum(vector<int> b)
{
    int s = 0;
    for (int c : b)
        s += c;
    return s;
}
int n;
void detect(int s, vector<int> b)
{
    vis[s] = true;
    b.push_back(s);
    for (int c : v[s])
    {
        if (!vis[c])
        {
            detect(c, b);
        }
        else
        {
            if (b[0] != c)
            {
                continue;
            }
            if (sum(b) < ans)
            {
                ans = sum(b);
                ansV = b;
            }
        }
    }
    vis[s] = false;
    b.pop_back();
}
int main()
{
    int e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    ans = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        memset(vis, false, sizeof(vis));
        detect(i, {});
    }
    sort(ansV.begin(), ansV.end());
    for (int c : ansV)
        cout << c << " ";
    return 0;
}