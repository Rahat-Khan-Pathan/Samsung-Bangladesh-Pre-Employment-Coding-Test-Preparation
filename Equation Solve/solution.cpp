#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll lg(long long N)
{
    ll value = 0;
    while (N >= 2.71828)
    {
        value++;
        N /= 2.71828;
    }
    return value;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, c, x;
        cin >> a >> b >> c >> x;
        ll ans = 0;
        for (ll i = 1; i <= 10000000; i++)
        {
            if (x % i == 0)
            {
                // cout << i << endl;
                ll val = a + (b * log2(i)) + (c * i * i);
                if (val == x / i)
                {
                    ans = i;
                    break;
                }
            }
        }
        // cout << lg(6285978519716) << endl;
        cout << ans << endl;
    }
    return 0;
}