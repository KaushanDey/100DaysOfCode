#include <bits/stdc++.h>
#include<string>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define max3(a,b,c) max(max(a,b),c)
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define fr(i,n) for(ll i=0;i<n;i++)
#define in_range(x,y,r,c) (x>=0 && x<r && y>=0 && y<c)

struct DSU{
    ll n;
    vector<ll> par;
    vector<ll> rnk;

    void make_set(){
        for(ll i=0;i<n;i++){
            par[i] = i;
            rnk[i] = 1;
        }
    }

    ll find_set(ll x){

        if(par[x]==x){
            return x;
        }
        return par[x] = find_set(par[x]);
    }

    void union_set(ll a, ll b){

        ll p1 = find_set(a);
        ll p2 = find_set(b);
        if(p1==p2) return;
        if(rnk[p1]>rnk[p2]){
            par[p2] = p1;
            rnk[p1]+=rnk[p2];
        }else{
            par[p1] = p2;
            rnk[p2]+=rnk[p1];
        }
    }
};

struct Edge{
    ll u,v;
    ll w;
};

bool compare(Edge a, Edge b){
    return (a.w < b.w);
}

int main()
{
    fastio;
    ll n;
    cin>>n;
    vector<vector<ll>> adj(n,vector<ll> (n));
    for(ll i=0;i<n;i++) for(ll j=0;j<n;j++) cin>>adj[i][j];
    vector<Edge> edges;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(adj[i][j]!=0) edges.push_back({i,j,adj[i][j]});
        }
    }

    sort(edges.begin(),edges.end(),compare);

    DSU dsu;
    dsu.n = n;
    dsu.make_set();
    ll sum = 0;
    ll cnt = 0;
    for(ll i=0;i<edges.size();i++){
        if(cnt==n-1) break;
        ll u = edges[i].u;
        ll v = edges[i].v;
        ll w = edges[i].w;
        if(dsu.find_set(u)==dsu.find_set(v)) continue;
        dsu.union_set(u,v);
        sum+=w;
        cnt++;
    }
    if(cnt==n-1) cout<<sum;
    else cout<<"IMPOSSIBLE";
}