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
const int MOD = 998244353;
const int MAXN = 12000005;
int n, q;

int a[MAXN], b[MAXN];

int c[MAXN];
int x[MAXN], y[MAXN];
int p = 1;
int dp[35], d[35];
//
void init()
{
    int check1 = 0;
    d[0] = 1;
    dp[0] = 1;
    F(i, 1, 30)
    {
        d[i] = (d[i - 1] * 2) % MOD;
        ll ok1 = (2LL * dp[i - 1]) % MOD;
        ll ok2 = (1LL * dp[i - 1] * d[i - 1]) % MOD;
        dp[i] = (ok1 + ok2) % MOD;
        check1 += i;
    }
}
void up(int u, int v)
{
    int ok = 1;
    if (c[u] > 0)
    {
        x[u] = d[v];
        y[u] = dp[v];
        ok = 0;
    }
    if (ok)
    {
        long long ans1 = a[u] ? x[a[u]] : 0;
        long long ans2 = b[u] ? x[b[u]] : 0;
        long long res1 = a[u] ? y[a[u]] : 0;
        long long res2 = b[u] ? y[b[u]] : 0;
        x[u] = (ans1 + ans2) % MOD;
        y[u] = (res1 + res2 + res1 * ans2) % MOD;
    }
}
void sovle_dp(int &u, int l, int r, int u1, int v1, int check, int v)
{
    int dummy = 1;
    if (!u)
    {
        u = ++p;
        dummy++;
    }
    if (u1 <= l && r <= v1)
    {
        c[u] += check;
        up(u, v);
        return;
    }
    int m = l + ((r - l) >> 1);
    if (u1 <= m)
    {
        sovle_dp(a[u], l, m, u1, v1, check, v - 1);
        dummy--;
    }
    if (v1 > m)
    {
        sovle_dp(b[u], m + 1, r, u1, v1, check, v - 1);
        dummy++;
    }
    up(u, v);
}

//
void S()
{
    cin >> n >> q;
    init();
    int u = 1;
    R(i, n)
    {
        int l, r;
        cin >> l >> r;
        sovle_dp(u, 0, (1 << 30) - 1, l, r, 1, 30);
    }
    cout << y[u] << "\n";
    R(i, q)
    {
        int t, l, r;
        cin >> t >> l >> r;
        int check = (t == 1) ? 1 : -1;
        sovle_dp(u, 0, (1 << 30) - 1, l, r, check, 30);
        cout << y[u] << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;

    while (t--)
        S();
    return 0;
}
