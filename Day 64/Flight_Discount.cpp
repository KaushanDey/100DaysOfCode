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

// struct Path{
//     ll dis,node,maxi;
// };

// struct Compare{

//     bool operator () (Path p1, Path p2){
//         return (p1.dis>p2.dis) || (p1.dis==p2.dis && p1.maxi>p2.maxi);
//     }
// };

// void Solution(vector<vector<pair<ll,ll>>> &adj, vector<ll> &dis){

//     priority_queue<Path, vector<Path>, Compare> pq;
//     dis[1] = 0;
//     pq.push({0,1,0});
//     while(!pq.empty()){
//         Path p = pq.top();
//         pq.pop();
//         ll u = p.node;
//         ll maxi = p.maxi;
//         if(p.dis>dis[u]) continue;
//         for(auto child:adj[u]){
//             ll v = child.first;
//             ll w = child.second;
//             if(u==1){
//                 ll t = w/2;
//                 if(dis[v]>dis[u]+t){
//                     dis[v] = dis[u]+t;
//                     pq.push({dis[v],v,w});
//                 }
//                 continue;
//             }
//             if(w>maxi){
//                 ll t = maxi/2;
//                 ll t1 = w/2;
//                 ll t2 = dis[u]-t+maxi+t1;
//                 if(dis[v]>t2){
//                     dis[v] = t2;
//                     pq.push({dis[v],v,w});
//                 }
//             }else{
//                 if(dis[v]>dis[u]+w){
//                     dis[v] = dis[u]+w;
//                     pq.push({dis[v],v,maxi});
//                 }
//             }
            
//         }
//     }

// }

struct Node{
    ll node,totalCost;
    bool discount;
};
struct  Compare{
    bool operator() (Node a, Node b){
        return (a.totalCost>b.totalCost);
    }
};
void Solution(vector<vector<pair<ll,ll>>> &adj, vector<vector<ll>> &dis){

    priority_queue<Node, vector<Node>, Compare> pq;
    pq.push({1,0,0});
    dis[1][0] = 0;
    dis[1][1] = 0;
    while(!pq.empty()){
        Node p = pq.top();
        pq.pop();
        ll u = p.node;
        ll discount = p.discount;
        if(discount==0){
            if(p.totalCost>dis[u][0]) continue;
            for(auto child: adj[u]){
                ll v = child.first;
                ll w = child.second;
                if(dis[v][0]>dis[u][0]+w){
                    dis[v][0] = dis[u][0]+w;
                    pq.push({v,dis[v][0],0});
                }
                if(dis[v][1]>dis[u][0]+floor(w/2)){
                    dis[v][1] = dis[u][0]+floor(w/2);
                    pq.push({v,dis[v][1],1});
                }
            }
        }
        if(discount==1){
            if(p.totalCost>dis[u][1]) continue;
            for(auto child: adj[u]){
                ll v = child.first;
                ll w = child.second;
                if(dis[v][1]>dis[u][1]+w){
                    dis[v][1] = dis[u][1]+w;
                    pq.push({v,dis[v][1],1});
                }
            }
        }
    }
}
int main() {

    fastio;
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> adj(n+1);
    for(ll i=0;i<m;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
    }
    vector<vector<ll>> dis(n+1,vector<ll> (2,LLONG_MAX));
    Solution(adj,dis);
    cout<<dis[n][1];
}