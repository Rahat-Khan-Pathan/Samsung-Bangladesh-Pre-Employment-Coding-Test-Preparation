#include <bits/stdc++.h>
#define ll long long
#define pub push_back
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;

class Hole
{
public:
    int si, sj, di, dj, c;
};
int n;
int si, sj, di, dj;
vector<Hole> v(100);
bool vis[100];
int finalAns;
void back(vector<int> &t)
{
    int ans = 0;
    int lasti = si, lastj = sj;
    for (int x : t)
    {
        ans += (abs(v[x].si - lasti) + abs(v[x].sj - lastj));
        ans += v[x].c;
        lasti = v[x].di;
        lastj = v[x].dj;
    }
    ans += (abs(di - lasti) + abs(dj - lastj));
    int ans2 = 0;
    int lasti2 = si, lastj2 = sj;
    for (int x : t)
    {
        ans2 += (abs(v[x].di - lasti2) + abs(v[x].dj - lastj2));
        ans2 += v[x].c;
        lasti2 = v[x].si;
        lastj2 = v[x].sj;
    }
    ans2 += (abs(di - lasti2) + abs(dj - lastj2));
    finalAns = min(finalAns, min(ans, ans2));
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
void solve()
{
    cin >> n;
    cin >> si >> sj >> di >> dj;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].si >> v[i].sj >> v[i].di >> v[i].dj >> v[i].c;
    }
    vector<int> t;
    finalAns = INT_MAX;
    back(t);
    cout << finalAns << endl;
}
int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
