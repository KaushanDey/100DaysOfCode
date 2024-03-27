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
ll N = 100000;
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

struct Edge{
    ll u,v,w;
};
bool Compare(Edge a, Edge b){
    return (a.w<b.w);
}
struct DSU{
    vll par;
    vll rnk;
    vll special;
    void make_set(ll n){
        par.resize(n+1);
        rnk.resize(n+1);
        for1(i,1,n){
            par[i] = i;
            rnk[i] = 1;
        }
    }

    ll find_set(ll u){
        if(par[u]==u) return u;
        return par[u] = find_set(par[u]);
    }

    bool make_union(ll u, ll v, ll &k){
        ll p1 = find_set(u);
        ll p2 = find_set(v);
        if(p1==p2) return false;
        if(rnk[p1]>rnk[p2]){
            par[p2] = p1;
            rnk[p1]+=rnk[p2];
            special[p1]+=special[p2];
            if(special[p1]==k) return true;
        }else{
            par[p1] = p2;
            rnk[p2]+=rnk[p1];
            special[p2]+=special[p1];
            if(special[p2]==k) return true;
        }
        return false;
    }
};
int main()
{
    fastio;
    ll n,m,k;
    cin>>n>>m>>k;
    vll a(k);
    DSU dsu;
    dsu.special.resize(n+1);
    for0(i,0,k){
        ll u;
        cin>>u;
        a[i] = u;
        dsu.special[u] = 1;
    }
    vector<Edge> edges;
    for0(i,0,m){
        ll u,v,w;
        cin>>u>>v>>w;
        edges.pb({u,v,w});
    }

    sort(edges.begin(),edges.end(),Compare);

    dsu.make_set(n);
    ll ans;
    for0(i,0,m){
        ll u = edges[i].u;
        ll v = edges[i].v;
        ll w = edges[i].w;
        ll p1 = dsu.find_set(u);
        ll p2 = dsu.find_set(v);
        if(p1==p2) continue;
        bool done = dsu.make_union(u,v,k);
        if(done){
            ans = w;
            break;
        }
    }
    for0(i,0,k) cout<<ans<<" ";

}