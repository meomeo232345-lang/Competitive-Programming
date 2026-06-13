#include <bits/stdc++.h>

using namespace std;

// mang
long long a[2005];
long long tong[2005];
int f[2005][2005];

void solve()
{
    int n, k;
    long long s;
    cin >> n >> k >> s;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        tong[i] = tong[i - 1] + a[i];
    }
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            f[i][j] = -1;
        }
    }
    f[0][0] = 0;
    for (int j = 1; j <= k; ++j)
    {
        for (int i = j; i <= n; ++i)
        {
            for (int m = j; m <= i; ++m)
            {
                if (f[m - 1][j - 1] != -1)
                {
                    long long sum_doan = tong[i] - tong[m - 1];
                    int dem = (sum_doan <= s) ? 1 : 0;

                    f[i][j] = max(f[i][j], f[m - 1][j - 1] + dem);
                }
            }
        }
    }
    cout << (f[n][k] == -1 ? 0 : f[n][k]) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
