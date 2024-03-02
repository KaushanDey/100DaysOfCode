#include <bits/stdc++.h>
#include<string>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define max3(a,b,c) max(max(a,b),c)
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define fr(i,n) for(ll i=0;i<n;i++)
ll gcd(ll a, ll b)
{
    return b==0?a:gcd(b,a%b);
}

vector<ll> team;
bool isPossible = true;
void dfs(ll node, vector<vector<ll>> &adj){
    if(!isPossible){
        return;
    }
    for(auto child : adj[node]){
        if(!isPossible) return;
        if(team[child]==team[node]){
            isPossible = false;
            return;
        }
        if(team[child]==0){
            team[child] = (team[node]==1)?2:1;
            dfs(child,adj);
        }
    }
}

int main()
{
    fastio;
    ll t=1;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<vector<ll>> adj(n);
        for(ll i=0;i<n;i++){
            ll x,y;
            cin>>x>>y;
            adj[x-1].push_back(y-1);
            adj[y-1].push_back(x-1);
        }
        for(ll i=0;i<n;i++){
            team.push_back(0);
        }
        for(ll i=0;i<n;i++){
            if(team[i]==0){
                team[i]=1;
                dfs(i,adj);
            }
        }
        if(!isPossible){
            cout<<"IMPOSSIBLE";
        }else{
            for(ll i=0;i<n;i++){
                cout<<team[i]<<" ";
            }
        }
    }
}