#include <bits/stdc++.h>
using namespace std;

int n, id, top;
int L[305], R[305], st[305];
int a[305], b[305];

int ask(int l, int r)
{
    cout << "? " << l << " " << r << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}
void solve()
{
    cin >> n;
    id = n;
    top = 0;
    for (int i = 1; i <= n; i++)
    {
        top++;
        L[top] = i;
        R[top] = i;
        st[top] = i;
        while (top >= 2)
        {
            int l = L[top - 1]; // left
            int r = R[top];     // Right
            if (ask(l, r) == 1)
            {
                id++;
                a[id] = st[top - 1];
                b[id] = st[top];
                top--;
                L[top] = l;
                R[top] = r;
                st[top] = id;
            }
            else
            {
                break;
            }
        }
    }
    cout << "! ";
    for (int i = n + 1; i < 2 * n; i++)
    {
        cout << a[i] << " " << b[i];
        if (i < 2 * n - 1)
            cout << " ";
    }
    cout << "\n";
    cout.flush();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
