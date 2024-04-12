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
#define cntzero(x) __builtin_ctzll(x)     // number of trailing zeros
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
#define vch vector<char>
#define vbool vector<bool>
#define pll pair<ll, ll>
#define mll map<ll, ll>
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vvch vector<vector<char>>
#define vvpll vector<vector<pair<ll, ll>>>
#define vvvll vector<vector<vector<ll>>>
#define cases(i) cout << "Case " << i << ":"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define rand(V) random_shuffle(all(V))
#define lb(a, X) lower_bound(all(a), X) - a.begin()
#define ub(a, X) upper_bound(all(a), X) - a.begin()
#define Tc    \
    ll t = 1; \
    cin >> t; \
    while (t--)
#define for0(i, l, r) for (ll i = l; i < r; i++)
#define for1(i, l, r) for (ll i = l; i <= r; i++)
#define rev0(i, r, l) for (ll i = r - 1; i >= l; i--)
ll N = 1e5;
ll MOD = 1e9 + 7;
vector<int> spf(N + 1, 0);
void smallestPrimeFactor()
{
    for (int i = 2; i <= N; i++)
    {
        if (!spf[i])
        {
            spf[i] = i;
            for (int j = i * i; j <= N; j += i)
            {
                if (!spf[j])
                    spf[j] = i;
            }
        }
    }
}
int main()
{
    fastio;
    Tc
    {
        ll n;
        cin >> n;
        vll a(n);
        ll odd = 0, even = 0;
        for0(i, 0, n)
        {
            cin >> a[i];
            if (a[i] % 2 == 0)
                even++;
            else
                odd++;
        }

        vvvll dp(n + 1, vvll(n + 1, vll(2)));

        for1(i, 0, n)
        {
            dp[0][i][0] = 1;
            dp[0][i][1] = 0;
        }

        for1(i, 0, n)
        {
            dp[1][i][1] = 1;
            if (i & 1)
                dp[1][i][0] = 1;
            else
                dp[1][i][0] = 0;
        }

        for1(i, 2, n)
        {
            for1(j, 0, n)
            {

                for0(k, 0, 2)
                {
                    bool takeOdd = false, takeEven = false;

                    // Alice takes odd
                    bool lose1 = false;

                    // Bob takes odd
                    if (i - 2 >= 0)
                    {
                        lose1 = lose1 | (dp[i-2][j][k^1]==0);
                        takeOdd = true;
                    }

                    //Bob takes even
                    if(j-1>=0){
                        lose1 = lose1 | (dp[i-1][j-1][k^1]==0);
                        takeOdd = true;
                    }

                    //Alice takes even
                    bool lose2 = false;

                    //Bob takes odd
                    if(j-1>=0){

                        lose2 = lose2 | (dp[i-1][j-1][k]==0);
                        takeEven = true;
                    }

                    //Bob takes even
                    if(j-2>=0){
                        lose2 = lose2 | (dp[i][j-2][k]==0);
                        takeEven = true;
                    }

                    bool res;
                    if(takeEven && takeOdd) res = lose1 && lose2;
                    else res = lose1 | lose2;

                    dp[i][j][k] = res^1;
                }
            }
        }

        cout<<((dp[odd][even][0])? "Alice\n": "Bob\n");
    }
}