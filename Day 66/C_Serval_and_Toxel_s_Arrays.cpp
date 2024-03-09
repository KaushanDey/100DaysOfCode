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
#define rep(i, l, r) for (long long i = l; i < r; i++)
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

int main()
{
    fastio;
    Tc
    {
        ll n, m;
        cin >> n >> m;
        vector<pll> v; // element aur uska starting point
        for0(i, 0, n)
        {
            ll a;
            cin >> a;
            v.pb({a, 0});
        }
        map<ll, vector<pll>> dp;
        for0(i, 0, m)
        {
            ll ind, val;
            cin >> ind >> val;
            ind--;

            dp[v[ind].first].pb({v[ind].second, i + 1});

            v[ind]={val,i+1};
        }

        for0(i, 0, n)
        {
            dp[v[i].first].pb({v[i].second, m + 1});
        }
        ll ans = 0;
        for (auto &it : dp)
        {
            ll e = it.first;
            ll t = 0;
            for (auto x : dp[e])
            {
                t += (x.second - x.first);
            }
            ll abs = (m + 1) - t;

            ans += (t * abs) + (t * (t - 1) / 2);
        }
        cout << ans << endl;
    }
}