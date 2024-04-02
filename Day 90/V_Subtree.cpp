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
#define vbool vector <bool>
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
ll N = 1e5;
ll MOD = 1e9+7;
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

vvll adj;
vll dp;
ll m;
vpll ans;

void dfs1(ll node, ll par){

    dp[node] = 1;
    for(auto &child: adj[node]){
        if(child==par) continue;
        dfs1(child,node);
        dp[node] = ((dp[node]%m)*((dp[child]%m)%m))%m;
    }
    dp[node]+=1;
}

void dfs2(ll node, ll par){

    ll t1 = dp[node];
    for(auto &child: adj[node]){
        if(child==par) continue;
        ll t2 = dp[child];
        dp[node]-=1;
        dp[node] = (dp[node]/(dp[child]))+1;
        dp[child]-=1;
        dp[child] = ((dp[child]%m)*(dp[node]%m))%m;
        dp[child]+=1;
        dfs2(child,node);
        ans.pb({child,(dp[child]-1)%m});
        dp[child] = t2;
        dp[node] = t1;
    }
    
}
int main()
{
    fastio;
    ll n;
    cin>>n>>m;
    adj.resize(n+1);
    for0(i,0,n-1){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dp.resize(n+1);
    dfs1(1,-1);
    ans.pb({1,(dp[1]-1)%m});
    dfs2(1,-1);
    sort(all(ans));
    for0(i,0,ans.size()){
        cout<<ans[i].second<<"\n";
    }
}