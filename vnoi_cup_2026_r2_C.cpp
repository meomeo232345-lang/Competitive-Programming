// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

// /*                    TEMPLATE              */  //

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

#define pb push_back
#define eb eplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#define F(i, a, b) for (int i = (a); i <= (b); ++i)
#define FD(i, a, b) for (int i = (a); i >= (b); --i)
#define R(i, n) for (int i = 0; i < (n); ++i)
#define RD(i, n) for (int i = (n) - 1; i >= 0; --i)
#define FN(i, a, b) for (int i = (a); i < (b); ++i)
#define E(a, x) for (auto &a : x)

const int N = 2e5 + 5;
const ll INF = 1e18;
const int M = 1e9 + 7;

void S()
{
    int n;
    cin >> n;
    auto ask = [&](int x, int y) -> int
    {
        cout << "? " << x << " " << y << "\n";
        cout.flush();
        string s;
        cin >> s;
        return (s[0] == 'T' ? 1 : 0);
    };
    //
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    mt19937 rng(chrono::system_clock::now().time_since_epoch().count() ^ n);
    shuffle(all(a), rng);
    int u = a[0];
    for (int i = 1; i < n; i++)
    {
        int v = a[i];
        int ok = ask(u, v);
        if (ok == 0)
        {
            u = v;
        }
    }

    //
    int d = u * 2;
    int dp = d / 2;
    int ans = dp + 0;
    //
    int check1 = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i == ans)
            continue;
        if (ask(ans, i) == 0 || ask(i, ans) == 1)
        {
            check1 = 0;
            break;
        }
    }
    //
    if (check1 == 1)
    {
        cout << "! " << ans << "\n";
    }
    else
    {
        cout << "! FRIENDLY\n";
    }
    cout.flush();
}
//
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        S();
    return 0;
}
