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
ll N = 100000;
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
        ll n, k;
        cin >> n >> k;
        vector<ll> a(2 * n);
        map<ll,ll> m1;
        map<ll,ll> m2;
        for (ll i = 0; i < n; i++){
            ll x;
            cin>>x;
            a[i]  = x;
            m1[x]++;
        }
        for (ll i = n; i < 2*n; i++){
            ll x;
            cin>>x;
            a[i]  = x;
            m2[x]++;
        }
        vector<ll> l;
        vector<ll> r;

        ll z = 0;
        for(auto &it: m1){
            if(it.second==2){
                l.pb(it.first);
                l.pb(it.first);
                z++;
            }
        }
        ll y = z;
        for(auto &it1: m2){
            if(it1.second==2 && y>0){
                r.pb(it1.first);
                r.pb(it1.first);
                y--;
            }
        }
        ll cnt = 2*(k - z);
        for(auto &it2: m2){
            if(it2.second==1 && cnt>0){
                l.pb(it2.first);
                r.pb(it2.first);
                cnt--;
            }
        }

        for0(i,0,2*k) cout<<l[i]<<" ";
        cout<<"\n";
        for0(i,0,2*k) cout<<r[i]<<" ";
        cout<<"\n";
        // map<ll,ll> vis;
        // for (ll i = 0; i < n; i++)
        // {
        //     if (vis[a[i]] == 0)
        //     {
        //         ll cnt = 0;
        //         for (ll j = n; j < 2 * n; j++)
        //         {
        //             if (a[i] == a[j])
        //             {
        //                 l.pb(a[i]);
        //                 r.pb(a[j]);
        //                 vis[a[i]] = 1;
        //                 cnt++;
        //                 break;
        //             }
        //         }
        //         if (cnt == 0)
        //         {
        //             storel.pb(a[i]);
        //             vis[a[i]]=1;
        //         }
        //     }
        // }
        // for(ll i=n;i<2*n;i++){
        //     if(vis[a[i]]==0){
        //         storer.pb(a[i]);
        //         vis[a[i]]=1;
        //     }
        // }

        // if(l.size()==2*k){
        //     printv(l);
        //     printv(r);
        // }else if(l.size()>2*k){
        //     while(l.size()>2*k){
        //         l.pop_back();
        //         r.pop_back();
        //     }
        //     printv(l);
        //     printv(r);
        // }else if(l.size()<2*k){
        //     ll n=storel.size();
        //     ll m = storer.size();
        //     ll i = 0;
        //     ll j=0;
        //     while(l.size()<2*k && i<n && j<m){
        //         l.pb(storel[i]);
        //         l.pb(storel[i]);
        //         r.pb(storer[j]);
        //         r.pb(storer[j]);
        //         i++;
        //         j++;
        //     }
        //     printv(l);
        //     printv(r);
        // }
    }
}