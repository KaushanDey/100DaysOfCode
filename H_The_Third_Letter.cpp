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

struct DSU{

    vector<ll> par;
    vector<ll> rnk;
    vector<ll> pos;

    void make_set(ll n){
        par.resize(n+1);
        rnk.resize(n+1);
        pos.resize(n+1);

        for(ll i=1;i<=n;i++){
            par[i] = i;
            pos[i]=0;
            rnk[i]=1;
        }
    }

    ll find_set(ll node){

        if(par[node]==node){
            return node;
        }
        pos[node] = pos[node]+pos[par[node]];
        par[node] = find_set(par[node]);
        
        return par[node];
    }

    bool union_set(ll u,ll v, ll d){

        ll p1 = find_set(u);
        ll p2 = find_set(v);
        if(p1==p2){
            if(pos[u]-pos[v]==d) return true;
            return false;
        }
        if(pos[p1]>pos[p2]){
            par[p2] = p1;
            ll t = pos[u]-d;
            pos[p2] = t-pos[v];
            //rnk[p1]+=rnk[p2];
            return true;
        }else{
            par[p1] = p2;
            ll t = pos[v]+d;
            pos[p1] = t-pos[u];
            //rnk[p2]+=rnk[p1];
            return true;
        }
    }

};
struct Edge{
    ll a,b,d;
};
int main()
{
    fastio;
    Tc
    {
        ll n,m;
        cin>>n>>m;
        vector<ll> arr(n+1,LLONG_MAX);
        vector<Edge> edges;
        bool isPossible = true;
        for(ll i=0;i<m;i++){
            ll a,b,d;
            cin>>a>>b>>d;
            edges.pb({a,b,d});
        }

        DSU dsu;
        dsu.make_set(n);

        for(auto &child: edges){
            ll u = child.a;
            ll v = child.b;
            ll d = child.d;
            ll p1 = dsu.find_set(u);
            ll p2 = dsu.find_set(v);
            if(p1==p2){
                if(dsu.pos[u]-dsu.pos[v]==d) isPossible = true;
                else isPossible = false;
            }
            isPossible = dsu.union_set(u,v,d);
            if(!isPossible) break;
        }
        if(!isPossible) cout<<"NO\n";
        else cout<<"YES\n";
    }
}