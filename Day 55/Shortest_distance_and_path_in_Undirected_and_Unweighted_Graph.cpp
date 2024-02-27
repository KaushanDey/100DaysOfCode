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
void shortestPath(vector<ll> &parent,ll node,ll &s){

    if(node==s){
        cout<<s<<" ";
        return;
    }
    shortestPath(parent,parent[node],s);
    cout<<node<<" ";
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
    parent[0] = -1;
    ll s,f;
    cin>>s>>f;
    dis[s]=0;
    q.push(s);
    while(!q.empty()){
        ll front = q.front();
        q.pop();
        for(ll i=0;i<n;i++){
            if(adj[front][i]!=0){
                if(dis[i]>dis[front]+1){
                    parent[i] = front;
                    dis[i] = dis[front]+1;
                    q.push(i);
                }
            }
        }
    }
    cout<<dis[f]<<"\n";
    shortestPath(parent,f,s);

}