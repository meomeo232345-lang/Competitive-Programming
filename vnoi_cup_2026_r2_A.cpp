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
    vll a(n + 5, 0);
    F(i, 1, n)
    {
        cin >> a[i]; // o(n)
    }
    vll d(n + 5, 0);
    ll x = 0;
    int ok1 = 0;
    int ok2 = 0;
    // subtask
    F(i, 3, n)
    {
        d[i] = d[i - 1];
        ll k = a[i] + a[i - 1] + a[i - 2];
        ll val = d[i - 3] + k;
        if (d[i] < val)
        {
            d[i] = val;
            ok1++;
        }
        else
        {
            ok2++;
        }
        x += ok1;
    }
    cout << d[n] << "\n";
}

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
