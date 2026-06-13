#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, rb, cb;
    cin >> n >> m >> rb >> cb;
    int time_r = (rb == 1) ? (n - 1) : (2 * n - rb - 1);
    int time_c = (cb == 1) ? (m - 1) : (2 * m - cb - 1);
    cout << min(time_r, time_c) << "\n";
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
