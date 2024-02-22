#include <bits/stdc++.h>
#include<string>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

bool possibility(vector<vector<ll>> &adj, vector<ll> &color,ll i, ll &n, ll &m){

    color[i] = 1;
    bool isPossible = true;
    for(ll j=0;j<adj[i].size();j++){
        if(!isPossible) break;
        if(color[adj[i][j]]==1){
            return false;
        }
        if(color[adj[i][j]]==0){
            isPossible = possibility(adj,color,adj[i][j],n,m);
        }
    }
    color[i]=2;
    return isPossible;
}

void topoSort(vector<vector<ll>> &adj, vector<ll> &in_deg,ll &n, ll &m){

    queue<ll> q;
    for(ll i=0;i<n;i++){
        if(in_deg[i]==0){
            q.push(i);
        }
    }

    queue<ll> topo_sort;
    while(!q.empty()){
        ll front = q.front();
        q.pop();
        topo_sort.push(front);
        for(ll i=0;i<adj[front].size();i++){
            in_deg[adj[front][i]]--;
            if(in_deg[adj[front][i]]==0){
                q.push(adj[front][i]);
            }
        }
    }

    for(ll i=0;i<n;i++){
        ll t = topo_sort.front();
        topo_sort.pop();
        cout<<t+1<<" ";
    }

}
int main()
{
    fastio;
    ll n,m;
    cin>>n>>m;
    ll x,y;
    vector<vector<ll>> adj(n);
    vector<ll> in_deg(n,0);
    for(ll i=0;i<m;i++){
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        in_deg[y-1]++;
    }
    vector<ll> color(n,0);
    ll isPossible = true;
    for(ll i=0;i<n;i++){
        if(!isPossible) break;
        if(color[i]==0){
            isPossible = possibility(adj,color,i,n,m);
        }
    }
    if(!isPossible){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    topoSort(adj,in_deg,n,m);
}