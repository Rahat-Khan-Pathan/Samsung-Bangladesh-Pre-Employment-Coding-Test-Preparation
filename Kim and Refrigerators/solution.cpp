#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
#define ll long long
using namespace std;
bool vis[100];
int finalAns;
int n, si, sj, di, dj;
vector<pair<int, int>> v(100);
void back(vector<int> &t)
{
    if (t.size() == n)
    {
        int ans = 0;
        int lasti = di, lastj = dj;
        for (int x : t)
        {
            ans += (abs(v[x].first - lasti) + abs(v[x].second - lastj));
            lasti = v[x].first;
            lastj = v[x].second;
        }
        ans += (abs(si - lasti) + abs(sj - lastj));
        finalAns = min(finalAns, ans);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            t.push_back(i);
            back(t);
            t.pop_back();
            vis[i] = false;
        }
    }
}
int cs = 1;
void solve()
{
    cin >> n;
    cin >> si >> sj >> di >> dj;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    memset(vis, false, sizeof(vis));
    vector<int> t;
    finalAns = INT_MAX;
    back(t);
    cout << "# " << cs++ << " " << finalAns << endl;
}
int main()
{
    ll t = 10;
    while (t--)
    {
        solve();
    }
    return 0;
}
