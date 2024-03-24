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
ll N = 100000;
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

void dfs1(vvll &adj1, ll node, vbool &vis, stack<ll> &st)
{

    vis[node] = 1;

    for (auto &child : adj1[node])
    {
        if (!vis[child])
        {
            dfs1(adj1, child, vis, st);
        }
    }
    st.push(node);
}

void dfs2(vvll &adj2, ll node, vll &cost, vbool &vis, vll &components,ll &mini)
{

    components.pb(node);
    mini = min(mini,cost[node]);
    vis[node] = 1;
    for (auto &child : adj2[node])
    {
        if (!vis[child])
        {
            dfs2(adj2, child, cost,vis, components,mini);
        }
    }
}

int main()
{
    fastio;
    ll n;
    cin >> n;
    vll cost(n + 1);
    cost[0] = 0;
    for1(i, 1, n) cin >> cost[i];
    ll m;
    cin >> m;
    vvll adj1(n + 1);
    vvll adj2(n + 1);
    for0(i, 0, m)
    {
        ll u, v;
        cin >> u >> v;
        adj1[u].pb(v);
        adj2[v].pb(u);
    }

    vbool vis(n + 1, false);
    stack<ll> st;
    for1(i, 1, n)
    {
        if (!vis[i])
            dfs1(adj1, i, vis, st);
    }

    vll topo;
    while (!st.empty())
    {
        topo.pb(st.top());
        st.pop();
    }
    vvll scc;
    vll components;
    vll minCost;
    ll totalCost = 0;
    vis.assign(n + 1, false);
    for0(i, 0, topo.size())
    {
        ll node = topo[i];
        if (!vis[node])
        {
            ll mini = INT_MAX;
            components.clear();
            dfs2(adj2, node,cost, vis, components,mini);
            minCost.pb(mini);
            totalCost+=mini;
            scc.pb(components);
        }
    }
    ll ans = 1;
    for0(i,0,scc.size()){
        ll cnt = 0;
        for0(j,0,scc[i].size()){
            if(cost[scc[i][j]]==minCost[i]){
                cnt++;
            }
        }
        ans = ((ans%MOD)*(cnt%MOD))%MOD;
    }

    cout<<totalCost<<" "<<ans;
}