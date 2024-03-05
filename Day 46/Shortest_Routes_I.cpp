#include <bits/stdc++.h>
#include<string>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define max3(a,b,c) max(max(a,b),c)
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define fr(i,n) for(ll i=0;i<n;i++)

void shortestPath(vector<vector<pair<ll,ll>>> &adj, vector<ll> &dis){

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    dis[1]=0;
    pq.push({0,1});
    while(!pq.empty()){
        pair<ll,ll> p = pq.top();
        pq.pop();
        ll u = p.second;
        if(p.first>dis[u]) continue;
        for(auto child: adj[u]){
            ll v = child.first;
            ll w = child.second;
            if(dis[v]>dis[u]+w){
                dis[v] = dis[u]+w;
                pq.push({dis[v],v});
            }
        }
    }
}
int main()
{
    fastio;
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> adj(n+1);
    for(ll i=0;i<m;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
    }
    vector<ll> dis(n+1,LLONG_MAX);
    shortestPath(adj,dis);
    for(ll i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
}