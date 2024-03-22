#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);                   \
    cin.exceptions(ios::badbit | ios::failbit);
#define all(v) v.begin(), v.end()
#define revall(v) v.rbegin(), v.rend()
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define F first
#define S second
#define pi acos(-1.0)
#define maxv(v) *max_element(all(v))
#define minv(v) *min_element(all(v))
#define countv(v, a) count(all(v), a)
#define cntone(x) __builtin_popcountll(x) // number of ones
#define cntzero(x) __builtin_ctzll(x)     // number of zeros
#define rep(i, l, r) for (ll i = l; i < r; i++)
#define SUM accumulate
#define toint(a) atoi(a.c_str())
#define read freopen("input.txt", "r", stdin)
#define write freopen("output.txt", "w", stdout)
#define Unique(c) (c).resize(unique(all(c)) - (c).begin())
#define sp(a) fixed << setprecision(a)
#define printv(container)     \
    for (auto it : container) \
        cout << it << " ";    \
    cout << endl
#define vll vector<ll>
#define pll pair<ll, ll>
#define mll map<ll, ll>
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vvch vector<vector<char>>
#define cases(i) cout << "Case " << i << ":"
#define yes cout << "yes" << endl
#define no cout << "no" << endl
#define rand(V) random_shuffle(all(V))
#define lb(a, X) lower_bound(all(a), X) - a.begin()
#define ub(a, X) upper_bound(all(a), X) - a.begin()
#define Tc    \
    ll t;     \
    cin >> t; \
    while (t--)
#define for0(i, l, r) for (ll i = l; i < r; i++)
#define for1(i, l, r) for (ll i = l; i <= r; i++)
#define rev0(i, r, l) for (ll i = r - 1; i >= l; i--)
#define MOD 1000000007

ll f(ll a)
{
    return (a + MOD) % MOD;
}


ll power(ll x, ll y)
{
    ll res = 1;
    x = x % MOD;

    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % MOD;

        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}

int main()
{
    fastio;
    Tc
    {
        ll n, k;
        cin >> n >> k;
        vll a(n);
        for0(i, 0, n) cin >> a[i];

        ll total = 0;
        for (auto it : a)
        {
            total = f(total + it);
        }

        ll max_sub = 0, temp = 0;

        for (auto it : a)
        {
            temp = ((temp) + (it));
            max_sub = (max(temp, max_sub));

            temp = (max(0LL, temp));
        }

        ll left = f(f(total) - f(max_sub));
        ll result = f(left + f(f(power(2, k))) * f(max_sub));
        cout << result << endl;
    }
}