#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n, 0);
        while (k--)
        {
            int mxLen = 0, lastIdx, cnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (v[i] == 0)
                    cnt++;
                else
                    cnt = 0;
                if (cnt >= mxLen)
                {
                    mxLen = cnt;
                    lastIdx = i;
                }
            }
            int s = lastIdx - mxLen + 1;
            int md = (lastIdx + s) / 2;
            v[md] = 1;
        }
        for (int i = 0; i < n; i++)
            cout << v[i];
        cout << endl;
    }
    return 0;
}
