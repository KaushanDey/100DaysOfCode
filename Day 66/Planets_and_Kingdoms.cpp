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

void dfs1(vector<vector<ll>> &g, vector<ll> &vis, stack<ll> &st, ll node){

    vis[node] = true;
    for(auto it : g[node]){
        if(!vis[it]){
            dfs1(g,vis,st,it);
        }
    }
    st.push(node);

}

void dfs2(vector<vector<ll>> &gr, vector<ll> &vis, vector<ll> &components, ll node){
    vis[node] = true;
    for(auto it:gr[node]){
        if(!vis[it]){
            dfs2(gr,vis,components,it);
        }
    }
    components.push_back(node);
}

int main()
{
    fastio;
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> g(n+1), gr(n+1);
    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    stack<ll> st;
    vector<ll> vis(n+1,false);

    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            dfs1(g,vis,st,i);
        }
    }

    vis.assign(n+1,false);
    vector<ll> components;
    vector<vector<ll>> scc;
    while(!st.empty()){
        ll i = st.top();
        st.pop();
        if(!vis[i]){
            components.clear();
            dfs2(gr,vis,components,i);
            scc.push_back(components);
        }
    }

    vector<ll> kingdom(n+1);
    ll k = 0;
    for(ll i=0;i<scc.size();i++){
        k++;
        for(ll j=0;j<scc[i].size();j++){
            kingdom[scc[i][j]] = k;
        }
    }
    cout<<k<<"\n";
    for(ll i=1;i<=n;i++){
        cout<<kingdom[i]<<" ";
    }
}