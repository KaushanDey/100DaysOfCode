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
vpll dp;
vpll ans;

void dfs1(ll node, ll par){
    ll m1 = 0;
    ll m2 = 0;
    for(auto &child: adj[node]){
        if(child!=par){
            dfs1(child,node);
            m2 = max(m2,dp[child].second+1);
            if(dp[child].first+1>m1){
                m2 = max(m2,m1);
                m1 = dp[child].first+1;
            }else{
                m2 = max(m2,dp[child].first+1);
            }
        }
    }
    dp[node] = {m1,m2};
}

void dfs2(ll node, ll par){

    ll t1 = dp[node].first;
    ll s1 = dp[node].second;
    for(auto &child: adj[node]){
        if(child!=par){
            ll t2 = dp[child].first;
            ll s2 = dp[child].second;
            if(t1-1==t2){
                dp[node].first = s1;
                if(s1+1>t2){
                    dp[child].first = s1+1;
                    dp[child].second = t2;
                }else if(s1+1>s2){
                    dp[child].second = s1+1;
                }
                ans.pb({child,dp[child].first});
            }else{
                dp[child].first = t1+1;
                dp[child].second = max(t2,s1+1);
                ans.pb({child,dp[child].first});
            }

            dfs2(child,node);
            dp[node].first = t1;
            dp[node].second = s1;
            dp[child].first = t2;
            dp[child].second = s2;
        }
    }
} 
int main()
{
    fastio;
    ll n;
    cin>>n;
    adj.resize(n+1);
    for0(i,0,n-1){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dp.resize(n+1);
    dfs1(1,-1);
    ans.pb({1,dp[1].first});
    dfs2(1,-1);
    sort(all(ans));
    for0(i,0,ans.size()) cout<<ans[i].second<<" ";
}