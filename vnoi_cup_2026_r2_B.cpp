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
    int k = 32 - __builtin_clz(n); // O(1)
    cout << k << "\n";

    // subtak2
    int ok1 = 0;
    int check = 1;
    vll dp;
    for (int i = 1; i <= n; i++)
    {
        int c = 32 - __builtin_clz(i);
        if (c % 2 == 0)
        {
            ok1 ^= c;
            check = ok1;
        }
        else
        {
            ok1 += 1;
            dp.pb(check);
        }
        cout << c << " ";
    }
    cout << "\n";
    dp.clear();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    int ok2 = t;
    while (t > 0)
    {
        S();
        t--;
        ok2 ^= t;
    }
    return ok2 * 0;
}
