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

void Solution(vector<vector<pair<ll,ll>>> &adj, vector<vector<ll>> &dis, ll &k){

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0,1});
    for(ll i=0;i<k;i++) dis[1][0] = 0;
    while(!pq.empty()){
        pair<ll,ll> p = pq.top();
        pq.pop();
        ll u = p.second;
        ll c = p.first;
        //check for stale node
        if(p.first>dis[u][k-1]) continue;
        for(auto child: adj[u]){
            ll v = child.first;
            ll w = child.second;
            if(dis[v][k-1]>c+w){
                dis[v][k-1] = c+w;
                pq.push({dis[v][k-1],v});
                sort(dis[v].begin(),dis[v].end());
            }

        }

    }
}
int main()
{
    fastio;
    ll n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<ll,ll>>> adj(n+1);
    for(ll i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    vector<vector<ll>> dis(n+1,vector<ll> (k,LLONG_MAX));
    Solution(adj,dis,k);
    for(ll i=0;i<k;i++){
        cout<<dis[n][i]<<" ";
    }
}