#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cin.exceptions(ios::badbit | ios::failbit);
#define all(v) v.begin(),v.end()
#define revall(v) v.rbegin(),v.rend()
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define F first
#define S second
#define pi acos(-1.0)
#define maxv(v) *max_element(all(v))
#define minv(v) *min_element(all(v))
#define countv(v,a) count(all(v),a)
#define cntone(x) __builtin_popcountll(x) // number of ones
#define cntzero(x) __builtin_ctzll(x) // number of trailing zeros
#define rep(i, l, r) for(long long i = l; i<r; i++)
#define SUM accumulate
#define toint(a) atoi(a.c_str())
#define read freopen("input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)
#define Unique(c) (c).resize(unique(all(c))-(c).begin())
#define sp(a) fixed<<setprecision(a)
#define printv(container) for(auto it:container) cout << it << " ";cout << endl
#define vll vector <ll>
#define pll pair<ll,ll>
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
#define lb(a,X) lower_bound(all(a),X)-a.begin()
#define ub(a,X) upper_bound(all(a),X)-a.begin()
#define Tc ll t=1;cin >> t;while(t--)
#define for0(i,l,r) for(ll i = l;i<r;i++)
#define for1(i,l,r) for(ll i = l;i<=r;i++)
#define rev0(i,r,l) for(ll i = r - 1;i>=l;i--)
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

void dfs(vvpll &adj, ll node, ll parent, vpll &par){

    for(auto &child: adj[node]){
        ll v = child.first;
        ll w = child.second;
        if(v!=parent){
            par[v] = {node,w};
            dfs(adj,v,node,par);
        }
    }
}

void path(vpll &par, ll node, vll &wt){
    if(par[node].first==node){
        return;
    }
    path(par,par[node].first);
    wt.pb(par[node].second);
}

void Solve(vpll &par, ll i, )
int main()
{
    fastio;
    Tc
    {
        ll n,a,b;
        cin>>n>>a>>b;
        vvpll adj(n+1);
        for0(i,0,n-1){
            ll u,v,w;
            cin>>u>>v>>w;
            adj[u].pb({v,w});
            adj[v].pb({u,w});
        }
        vpll par(n+1);
        for1(i,1,n) par[i] = {i,0};
        dfs(adj,a,a,par);
        vll wt;
        path(par,b,wt);
        bool isPossible = true;
        ll k = par[b].second;
        if(k==0){
            cout<<"YES\n";
            continue;
        }
            
    }
}