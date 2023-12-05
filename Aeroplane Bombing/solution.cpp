#include <bits/stdc++.h>
using namespace std;
int cs = 1;
int dfs(int i, int j, bool canBomb, vector<vector<int>> v, int n)
{
    if (i < 0)
        return 0;
    if (v[i][j] == 2)
        return 0;
    int ans = 0;
    if (v[i][j] == 1)
        ans++;
    if (canBomb)
    {
        // we will use the bomb here
        vector<vector<int>> cpy = v;
        for (int p = max(i - 5, 0); p < i; p++)
        {
            for (int q = 0; q < 5; q++)
            {
                if (cpy[p][q] == 2)
                    cpy[p][q] = 0;
            }
        }
        int op1 = 0, op2 = 0, op3 = 0;
        if (j + 1 < 5) // move to the right
            op1 = dfs(i - 1, j + 1, false, cpy, n);
        if (j - 1 >= 0) // move to the left
            op2 = dfs(i - 1, j - 1, false, cpy, n);
        op3 = dfs(i - 1, j, 0, cpy, n); // stay in the current place
        int finalAns1 = max({op1, op2, op3}) + ans;

        // we will not use the bomb
        int op1n = 0, op2n = 0, op3n = 0;
        if (j + 1 < 5)
            op1n = dfs(i - 1, j + 1, true, v, n);
        if (j - 1 >= 0)
            op2n = dfs(i - 1, j - 1, true, v, n);
        op3n = dfs(i - 1, j, 1, v, n);
        int finalAns2 = max({op1n, op2n, op3n}) + ans;
        return max(finalAns1, finalAns2);
    }
    else
    {
        // we can not use the bomb
        int op1n = 0, op2n = 0, op3n = 0;
        if (j + 1 < 5)
            op1n = dfs(i - 1, j + 1, false, v, n);
        if (j - 1 >= 0)
            op2n = dfs(i - 1, j - 1, false, v, n);
        op3n = dfs(i - 1, j, 0, v, n);
        int finalAns2 = max({op1n, op2n, op3n}) + ans;
        return finalAns2;
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1, vector<int>(5, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> v[i][j];
        }
    }
    for (int j = 0; j < 5; j++)
    {
        v[n].push_back(0);
    }
    cout << "#" << cs++ << " " << dfs(n, 2, true, v, n) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}