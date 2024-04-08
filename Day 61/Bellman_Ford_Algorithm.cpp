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

struct Edge{
    ll u,v,w;
};
int main()
{
    fastio;
    ll n,m;
    cin>>n>>m;
    vector<Edge> edges(m);
    for(ll i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        edges[i] = {u,v,w};
    }
    vector<ll> dis(n,INT_MAX);
    dis[0] = 0;
    for(ll i=0;i<n-1;i++){
        for(auto it:edges){
            ll u = it.u;
            ll v = it.v;
            ll w = it.w;
            if(dis[v]>dis[u]+w){
                dis[v] = dis[u]+w;
            }
        }
    }

    //for nth time
    for(auto it:edges){
        ll u = it.u;
        ll v = it.v;
        ll w = it.w;
        if(dis[v]>dis[u]+w){
            cout<<"Graph has negative cycle";
            return 0;
        }
    }
}
