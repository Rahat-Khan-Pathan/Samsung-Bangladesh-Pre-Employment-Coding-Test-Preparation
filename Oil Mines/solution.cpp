#include <bits/stdc++.h>
using namespace std;

int c, n, ans;
int oilMine[20];
bool vis[20];
void back(int i, int sum, int companies, int mn, int mx)
{
    if (vis[i])
    {
        if (companies == c)
        {
            int newMin = min(sum, mn);
            int newMax = max(sum, mx);
            ans = min(ans, newMax - newMin);
        }
        return;
    }
    int j = (i + 1) % n;
    vis[i] = true;
    // add this mine to the same company.
    back(j, sum + oilMine[i], companies, mn, mx);
    int newMin = min(sum, mn);
    int newMax = max(sum, mx);
    // add this mine to a new company.
    back(j, oilMine[i], companies + 1, newMin, newMax);
    vis[i] = false;
}
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        cin >> c >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> oilMine[i];
            vis[i] = false;
        }

        ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            back(i, 0, 1, INT_MAX, INT_MIN);
        }

        if (c > n)
            ans = -1;

        cout << ans << endl;
    }
    return 0;
}
