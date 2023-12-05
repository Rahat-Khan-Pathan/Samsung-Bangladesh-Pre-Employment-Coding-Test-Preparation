#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, greater<int>());
    int ans = 0;
    int d = n - 1;
    while (k--)
    {
        for (int i = 0; i < n; i++)
        {
            ans += a[d];
            a[i] -= a[d];
        }
        d--;
    }
    cout << ans << endl;
    return 0;
}