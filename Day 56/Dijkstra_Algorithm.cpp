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
ll gcd(ll a, ll b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    fastio;
    ll n;
    cin>>n;
    vector<vector<ll>> adj(n,vector<ll> (n));
    for(ll i=0;i<n;i++) for(ll j=0;j<n;j++) cin>>adj[i][j];
    vector<ll> dis(n,INT_MAX);
    queue<ll> q;
    vector<ll> parent(n);
    ll s,f;
    cin>>s>>f;
    parent[s] = -1;
    dis[s] = 0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        pair<ll,ll> top = pq.top();
        pq.pop();
        ll u = top.second;
        if(top.first>dis[u]) continue;
        for(ll i=0;i<n;i++){
            if(adj[u][i]!=0){
                ll v = i;
                ll w = adj[u][i];
                if(dis[v]>dis[u]+w){
                    dis[v] = dis[u]+w;
                    pq.push({dis[v],v});
                }
            }
        }
    }
    cout<<dis[f];
}