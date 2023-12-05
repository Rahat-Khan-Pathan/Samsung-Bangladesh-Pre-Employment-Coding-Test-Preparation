#include <bits/stdc++.h>
using namespace std;
int n;
int a[20];
int ans;
void back(int car, int dis, int pos, int type, int fuel)
{
    if (dis > ans)
        return;
    if (car == n)
    {
        // cout << dis << endl;
        ans = min(ans, dis);
        return;
    }
    if (pos == 0)
    {
        back(car, dis + 1, pos + 1, 1, 2); // Go to the right
        return;
    }
    if (pos == n + 1)
    {
        back(car, dis + 1, pos - 1, 2, 2); // Go to the left
        return;
    }

    int nextPos, refillCost, refillLoc;
    // determing next position and fuel station according to current fuel
    if (type == 1)
    {
        nextPos = 1;
        refillCost = pos;
        refillLoc = 0;
    }
    else
    {
        nextPos = -1;
        refillCost = n - pos + 1;
        refillLoc = n + 1;
    }
    if (type == a[pos])
    {
        if (fuel > 0)
        {
            int x = a[pos];
            a[pos] = 0;
            // Fill the car with 1 liter and you've two options. Go to the next position according to the fuel, or
            // refill the fuel
            back(car + 1, dis + 1, pos + nextPos, type, fuel - 1);
            back(car + 1, dis + refillCost, refillLoc, type, fuel);
            a[pos] = x;
        }
        // move to the next position without filling the car
        back(car, dis + 1, pos + nextPos, type, fuel);
    }
    else
    {
        // if fuel and car type doesn't match, go to the next position according to your robot's fuel
        back(car, dis + 1, pos + nextPos, type, fuel);
    }
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ans = INT_MAX;
    back(0, 0, 0, 0, 0);
    cout << ans - 1 << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}