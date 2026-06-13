#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    vector<long long> ga(n), gb(n);
    for (int i = 0; i < n; ++i)
    {
        ga[i] = min(a[i], k - a[i]);
        gb[i] = min(b[i], k - b[i]);
    }
    if (ga != gb)
    {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < n;)
    {
        int j = i;
        while (j < n && ga[j] == ga[i])
        {
            j++;
        }
        vector<long long> sub_a(a.begin() + i, a.begin() + j);
        vector<long long> sub_b(b.begin() + i, b.begin() + j);
        sort(sub_a.begin(), sub_a.end());
        sort(sub_b.begin(), sub_b.end());
        if (sub_a != sub_b)
        {
            cout << "NO\n";
            return;
        }
        i = j;
    }
    cout << "YES\n";
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
