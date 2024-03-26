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

void dfs(vvll &adj, ll &x, ll node, ll p, vvll &par, vll &depth){

    par[node][0] = p;
    for1(i,1,x){
        par[node][i] = par[par[node][i-1]][i-1];
    }

    for(auto &child: adj[node]){
        if(child!=p){
            depth[child] = depth[node]+1;
            dfs(adj,x,child,node,par,depth);
        }
    }
}

ll find_kth(ll node, ll d,ll &x, vvll &par){

    for(ll i=x;i>=0;i--){
        if(d&(1<<i)){
            node = par[node][i];
        }
    }
    return node;
}

ll lca(ll a, ll b, ll &x, vll &depth,vvll &par){

    if(depth[a]>depth[b]){
        ll temp = a;
        a = b;
        b = temp;
    }

    ll d = depth[b]-depth[a];
    b = find_kth(b,d,x,par);

    if(a==b) return a;

    for(ll i=x;i>=0;i--){
        if(par[a][i]!=par[b][i]){
            a = par[a][i];
            b = par[b][i];
        }
    }

    return par[a][0];
}

int main()
{
    fastio;
    ll caseNo = 0;
    Tc
    {
        caseNo++;
        ll n;
        cin>>n;
        vvll adj(n+1);
        for1(i,1,n){
            ll m;
            cin>>m;
            for0(j,0,m){
                ll v;
                cin>>v;
                adj[i].pb(v);
                adj[v].pb(i);
            }
        }
        ll x = log2(n);
        vvll par(n+1, vll (x+1));
        for1(i,1,n){
            for1(j,0,x){
                par[i][j] = i;
            }
        }

        vll depth(n+1);
        depth[1] = 0;
        depth[0] = 0;
        dfs(adj,x,1,1,par,depth);

        ll q;
        cin>>q;
        cout<<"Case "<<caseNo<<":\n";
        while(q--){
            ll v,w;
            cin>>v>>w;
            cout<<lca(v,w,x,depth,par)<<"\n";
        }
        
    }
}