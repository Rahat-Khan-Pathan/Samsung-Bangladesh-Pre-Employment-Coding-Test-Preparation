#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, k;
    cin >> a >> b >> k;
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    int ans = 0;
    for (int i = a; i <= b; i++)
    {
        int nm = i;
        int frq[10] = {0};
        while (nm)
        {
            int dig = nm % 10;
            frq[dig]++;
            nm /= 10;
        }
        int cnt = 0;
        for (int j = 0; j < n; j++)
            cnt += frq[ar[j]];
        if (cnt < k)
            ans++;
        else
            cout << i << endl;
    }
    cout << ans << endl;
    return 0;
}