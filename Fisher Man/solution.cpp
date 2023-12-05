#include <bits/stdc++.h>
#define ll long long
#define pub push_back
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;
int n;
int a[20], b[20];
void back()
{
    int finalAns = INT_MAX;
    for (int i = 1; i <= n - (b[0] + b[1] + b[2]) + 1; i++)
    {
        for (int j = i + b[0]; j <= n - (b[1] + b[2]) + 1; j++)
        {
            for (int k = j + b[1]; k <= n - (b[2]) + 1; k++)
            {
                int ans = 0;
                for (int p = i; p < i + b[0]; p++)
                {
                    ans += (abs(a[0] - p) + 1);
                }
                for (int p = j; p < j + b[1]; p++)
                {
                    ans += (abs(a[1] - p) + 1);
                }
                for (int p = k; p < k + b[2]; p++)
                {
                    ans += (abs(a[2] - p) + 1);
                }
                // cout << i << " " << j << " " << k << " " << ans << endl;
                finalAns = min(ans, finalAns);
            }
        }
    }
    cout << finalAns << endl;
}
void solve()
{
    cin >> n;
    for (int i = 0; i < 3; i++)
        cin >> a[i];
    for (int i = 0; i < 3; i++)
        cin >> b[i];
    back();
}
int main()
{
    fast;
    solve();
    return 0;
}
