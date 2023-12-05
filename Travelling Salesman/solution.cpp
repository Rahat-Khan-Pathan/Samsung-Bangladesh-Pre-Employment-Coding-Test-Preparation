#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll a[20][20];
bool vis[20];
ll ans;
void back(ll i, vector<ll> &v)
{
    if (v.size() == n - 1)
    {
        ll last = 0, s = 0;
        for (ll c : v)
        {
            s += a[last][c];
            last = c;
        }
        s += a[last][0];
        ans = min(ans, s);
    }
    for (ll p = 1; p < n; p++)
    {
        if (vis[p])
            continue;
        if (a[i][p] == 0)
            continue;
        vis[p] = true;
        v.push_back(p);
        back(p, v);
        vis[p] = false;
        v.pop_back();
    }
}
void solve()
{
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    ans = 1e18;
    memset(vis, false, sizeof(vis));
    vector<ll> v;
    back(0, v);
    cout << ans << endl;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}