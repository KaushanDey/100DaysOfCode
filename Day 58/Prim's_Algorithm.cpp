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

struct Edge{
    ll par,u,w;
};
struct Compare{
    bool operator () (Edge a, Edge b){
        return (a.w > b.w);
    }
};


void primMst(vector<vector<pair<ll,ll>>> &adj, ll &n){

    vector<bool> vis(n,false);

    priority_queue<Edge, vector<Edge>, Compare> pq;
    pq.push({0,0,0});
    ll sum = 0;
    vector<Edge> ans;
    ll edges = 0;
    while(!pq.empty()){
        Edge top = pq.top();
        pq.pop();
        ll u = top.u;
        ll par = top.par;
        ll w = top.w;
        if(!vis[u]){
            vis[u] = 1;
            if(u!=0) ans.pb(top);
            edges++;
            sum+=w;
            for(auto &child: adj[u]){
                ll v = child.first;
                ll w = child.second;
                if(!vis[v]){
                    pq.push({u,v,w});
                }
            }
        }
    }

    for0(i,0,ans.size()){
        cout<<ans[i].par<<" - "<<ans[i].u<<"  "<<ans[i].w<<"\n";
    }

    cout<<"\n"<<sum<<"\n";
}
int main()
{
    fastio;
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> adj(n);
    for(ll i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }

    primMst(adj,n);

}