#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void path(ll node, vector<ll> &d){
	if(d[node]==node){
		cout<<node;
		return;
	}
	cout<<node<<"->";
	path(d[node],d);
}
int main() {
	
    ll n,m,stages;
    cout<<"Enter the number of stages: ";
    cin>>stages;
    cout<<"Enter number of vertices: "; cin>>n;
    cout<<"Enter number of edges: "; cin>>m;
    vector<vector<ll> > v(stages+1);
    for(ll i=0;i<stages;i++){
    	cout<<"Enter the number of vertices in stage "<<i+1<<": ";
    	ll t;
    	cin>>t;
    	cout<<"Enter the vertices in stage "<<i+1<<": ";
    	for(ll j=0;j<t;j++){
    		ll u;
    		cin>>u;
    		v[i+1].push_back(u);
		}
	}
	vector<vector<pair<ll,ll> > > adj(n+1);
	cout<<"Enter the edges of the graph in the format src-dest-weight: \n";
	for(ll i=0;i<m;i++){
		ll a,b,w;
		cin>>a>>b>>w;
		adj[a].push_back({b,w});
	}
	
	ll target = v[stages][0];
	vector<ll> cost(n+1,LLONG_MAX);
	vector<ll> d(n+1);
	cost[target] = 0;
	d[target] = target;
	for(ll i = stages-1;i>=1;i--){
		for(ll j=0;j<v[i].size();j++){
			ll p = v[i][j];
			ll minv = LLONG_MAX;
			ll mind;
			for(ll k=0;k<adj[p].size();k++){
				ll d1 = adj[p][k].first;
				ll w = adj[p][k].second;
				if(minv>w+cost[d1]){
					minv = w+cost[d1];
					mind = d1;
				}
			}
			cost[p] = minv;
			d[p] = mind;
		}
	}
	
	
	cout<<"Shortest path from source to sink = "<<cost[v[1][0]]<<"\n";
	path(v[1][0],d);

    return 0;
}

/*
5
12
21
1
1
4
2 3 4 5
3
6 7 8
3
9 10 11
1
12
1 2 9
1 3 7
1 4 3
1 5 2
2 6 4
2 7 2
2 8 1
3 6 2
3 7 7
4 8 11
5 7 11
5 8 8
6 9 6
6 10 5
7 9 4
7 10 3
8 10 5
8 11 6
9 12 4
10 12 2
11 12 5
*/
