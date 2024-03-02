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

ll min_key(vector<ll> dis, vector<bool> mstSet, ll &n){
    
    ll min = INT_MAX, min_index;
    for(ll v=0;v<n;v++){
        if(mstSet[v]==false && dis[v]<min){
            min = dis[v];
            min_index = v;
        }
    }

    return min_index;
}

void primMst(vector<vector<ll>> &adj, ll &n){

    vector<bool> mstSet(n,false);
    vector<ll> dis(n,INT_MAX);
    vector<ll> par(n);
    par[0] = -1;
    dis[0] = 0;
    ll sum = 0;
    for(ll cnt = 0;cnt<n;cnt++){

        ll u = min_key(dis,mstSet);

        mstSet[u] = true;
        sum+=dis[u];
        cnt++;
        for(ll v = 0;v<n;v++){

            if(adj[u][v]!=0 && mstSet[v]==false && adj[u][v]<dis[v]){

                par[v] = u;
                dis[v] = adj[u][v];

            }
        }
    }

    cout<<sum;
}
int main()
{
    fastio;
    ll n;
    cin>>n;
    vector<vector<ll>> adj(n,vector<ll> (n));
    for(ll i=0;i<n;i++) for(ll j=0;j<n;j++) cin>>adj[i][j];

    primMst(adj,n);

}