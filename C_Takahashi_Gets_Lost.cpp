#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define fr(i, n) for (ll i = 0; i < n; i++)
#define in_range(i, j, h, w) (i >= 0 && i < h && j >= 0 && j < w)
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

ll Solution(vector<string> &s, string &t, ll &n, ll i, ll j, ll &h, ll &w, ll index)
{

    if (index == (n - 1))
    {
        if (t[index] == 'L' && in_range(i, j - 1, h, w) && s[i][j - 1] != '#')
        {
            return 1;
        }
        if (t[index] == 'U' && in_range(i - 1, j, h, w) && s[i - 1][j] != '#')
        {
            return 1;
        }
        if (t[index] == 'D' && in_range(i + 1, j, h, w) && s[i + 1][j] != '#')
        {
            return 1;
        }
        if (t[index] == 'R' && in_range(i, j + 1, h, w) && s[i][j + 1] != '#')
        {
            return 1;
        }
        return 0;
    }

    if (t[index] == 'L' && in_range(i, j - 1, h, w) && s[i][j - 1] != '#')
    {
        return Solution(s, t, n, i, j - 1, h, w, index + 1);
    }
    if (t[index] == 'U' && in_range(i - 1, j, h, w) && s[i - 1][j] != '#')
    {
        return Solution(s, t, n, i - 1, j, h, w, index + 1);
    }
    if (t[index] == 'D' && in_range(i + 1, j, h, w) && s[i + 1][j] != '#')
    {
        return Solution(s, t, n, i + 1, j, h, w, index + 1);
    }
    if (t[index] == 'R' && in_range(i, j + 1, h, w) && s[i][j + 1] != '#')
    {
        return Solution(s, t, n, i, j + 1, h, w, index + 1);
    }
    return 0;
}
int main()
{
    fastio;
    ll h, w, n;
    cin >> h >> w >> n;
    string t;
    cin >> t;
    vector<string> s(n);
    for (ll i = 0; i < h; i++)
        cin >> s[i];
    ll ans = 0;
    for (ll i = 0; i < h; i++)
    {
        for (ll j = 0; j < w; j++)
        {
            if (s[i][j] == '.')
            {
                ans += Solution(s, t, n, i, j, h, w, 0);
            }
        }
    }
    cout<<ans;
}