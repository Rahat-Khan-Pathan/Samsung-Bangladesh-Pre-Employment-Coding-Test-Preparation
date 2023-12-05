#include <bits/stdc++.h>
using namespace std;
int n;
int a[20];
bool visA[20]; // track to the left camels
bool visB[20]; // track to the right camels
int ans;
void back(bool isLeft, int cost)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (visB[i])
        {
            cnt++;
        }
    }
    if (cnt == n)
    {
        ans = min(ans, cost);
        return;
    }
    if (isLeft)
    {
        // all combinations of sending two camels to the right side
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (visA[i] && visA[j])
                {
                    visA[i] = false;
                    visA[j] = false;
                    visB[i] = true;
                    visB[j] = true;
                    back(false, cost + max(a[i], a[j]));
                    visA[i] = true;
                    visA[j] = true;
                    visB[i] = false;
                    visB[j] = false;
                }
            }
        }
    }
    else
    {
        // all combinations of sending one camel to the left side
        for (int i = 0; i < n; i++)
        {
            if (visB[i])
            {
                visB[i] = false;
                visA[i] = true;
                back(true, cost + a[i]);
                visB[i] = true;
                visA[i] = false;
            }
        }
    }
}
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    memset(visA, true, sizeof(visA));
    memset(visB, false, sizeof(visB));
    ans = INT_MAX;
    back(true, 0);
    cout << ans << endl;
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