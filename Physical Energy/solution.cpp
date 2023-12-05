#include <bits/stdc++.h>
using namespace std;
int dp[5000][5000][10];
int solve(int h, int d, int cost[], int time[], int n)
{
    if (n == 0 && d == 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1000;
    }
    if (dp[h][d][n] != -1)
        return dp[h][d][n];
    if (cost[n - 1] <= h)
    {
        int op1 = solve(h - cost[n - 1], d - 1, cost, time, n) + time[n - 1]; // take it
        int op2 = solve(h, d, cost, time, n - 1);                             // don't take it
        return dp[h][d][n] = min(op1, op2);
    }
    else
    {
        return dp[h][d][n] = solve(h, d, cost, time, n - 1);
    }
}
int main()
{
    int h, d;
    cin >> h >> d;
    int cost[] = {4, 5, 2, 3, 6};
    int time[] = {200, 210, 230, 235, 215};
    memset(dp, -1, sizeof(dp));
    cout << solve(h, d, cost, time, 5);

    return 0;
}