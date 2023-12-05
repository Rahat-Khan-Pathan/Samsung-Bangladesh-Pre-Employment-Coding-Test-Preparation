#include <bits/stdc++.h>
#define ll long long
using namespace std;
// 1(+),2(-),3(*),4(/)
vector<char> vp = {'+', '-', '*', '/'};
ll n, m, o, k;
ll a[20];
ll b[20];
bool valid(string s)
{
    if (s.size() == 0)
        return false;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            if (s[s.size() - 1] == '=')
                return true;
            else
                return false;
        }
    }
    return true;
}
ll getSum(string &s)
{
    ll ans = 0;
    ll cnt = 0;
    char prevSign = '.';
    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            cnt *= 10;
            cnt += (s[i] - '0');
        }
        else
        {
            if (prevSign == '+')
            {
                ans += cnt;
            }
            else if (prevSign == '-')
            {
                ans -= cnt;
            }
            else if (prevSign == '*')
            {
                ans *= cnt;
            }
            else if (prevSign == '/' && cnt && ans % cnt == 0)
            {
                ans /= cnt;
            }
            else if (prevSign == '.')
            {
                ans = cnt;
            }
            cnt = 0;
            prevSign = s[i];
        }
    }
    if (s[s.size() - 1] != '=')
        ans = cnt;
    return ans;
}
ll finalAns;
void back(string &s, ll op, bool isOpUsed)
{
    if (op > o)
        return;
    if (s.size() > finalAns)
        return;
    if (valid(s) && (getSum(s) > 1000))
        return;
    if (isOpUsed)
    {
        if (op < o && s[s.size() - 1] >= '0' && s[s.size() - 1] <= '9')
        {
            string t = s;
            t += '=';
            ll ans = getSum(t);
            if (ans == k)
            {
                finalAns = min(finalAns, op + 1);
            }
        }
    }
    else if (s.size())
    {
        ll ans = getSum(s);
        if (ans == k)
        {
            finalAns = min(finalAns, op);
        }
    }
    for (ll i = 0; i < n; i++)
    {
        string t = s + char(a[i] + '0');
        back(t, op + 1, isOpUsed);
    }
    if (s.size() && s[s.size() - 1] >= '0' && s[s.size() - 1] <= '9' && op < o - 1)
    {
        for (ll i = 0; i < m; i++)
        {
            string t = s + char(vp[b[i] - 1]);
            back(t, op + 1, true);
        }
    }
}
void solve()
{
    cin >> n >> m >> o;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < m; i++)
        cin >> b[i];
    cin >> k;
    finalAns = 1e18;
    string s = "";
    back(s, 0, false);
    cout << finalAns << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}