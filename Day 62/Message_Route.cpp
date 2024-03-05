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

void showPath(vector<ll> &parent, ll node){
    if(node==1){
        cout<<1<<" ";
        return;
    }
    showPath(parent,parent[node]);
    cout<<node<<" ";
}
void bfs(vector<vector<ll>> &adj, vector<ll> &dis, vector<ll> &parent){

    dis[1] = 0;
    parent[1] = -1;
    queue<ll> q;
    q.push(1);
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        for(ll i=0;i<adj[u].size();i++){
            ll v = adj[u][i];
            if(dis[v]>dis[u]+1){
                dis[v] = dis[u]+1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}
int main()
{
    fastio;
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> adj(n+1);
    for(ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<ll> dis(n+1,INT_MAX);
    vector<ll> parent(n+1);
    bfs(adj,dis,parent);
    if(dis[n]==INT_MAX){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    cout<<dis[n]+1<<"\n";
    showPath(parent,n);

}