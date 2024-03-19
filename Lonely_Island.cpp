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

void dfs(vvll &adj, ll node, stack<ll> &st, vector<bool> &vis){

    vis[node] = 1;

    for(auto &child:adj[node]){
        if(!vis[child]){
            dfs(adj,child,st,vis);
        }
    }

    st.push(node);
}
int main()
{
    fastio;
    ll n,m,r;
    cin>>n>>m>>r;
    vvll adj(n+1);
    vll in_deg(n+1);
    vll out_deg(n+1);
    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        in_deg[v]++;
        out_deg[u]++;
        adj[u].pb(v);
    }

//     vector<bool> vis(n+1,false);
//     stack<ll> st;
//     for(ll i=1;i<=n;i++){
//         if(!vis[i]){
//             dfs(adj,i,st,vis);
//         }
//     }

//     while(st.size()>1) st.pop();
//     cout<<st.top();
// }
    vll ans;
    for(ll i=1;i<=n;i++){
        if(out_deg[i]==0){
            ans.pb(i);
        }
    }
    sort(ans.begin(),ans.end());
    for(ll i=0;i<ans.size();i++) cout<<ans[i]<<" ";
}