#include <bits/stdc++.h>
#include<string>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define max3(a,b,c) max(max(a,b),c)
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define fr(i,n) for(ll i=0;i<n;i++)
#define in_range(x,y,n,m) (x>=0 && x<n && y>=0 && y<m)

void bfs(vector<vector<ll>> &arr, vector<vector<ll>> &dis,ll &n, ll &m,ll r,ll c){

    queue<pair<ll,ll>> q;
    pair<ll,ll> mp = {r,c};
    q.push(mp);
    dis[r][c]=0;
    ll a,b;
    while(!q.empty()){
        pair<ll,ll> front = q.front();
        ll i = front.first;
        ll j = front.second;
        q.pop();
        //north
        a = i-1;
        b = j;
        if(in_range(a,b,n,m) && dis[a][b]>(dis[i][j]+1) && arr[a][b]==0){
            dis[a][b]=dis[i][j]+1;
            pair<ll,ll> mp = {a,b};
            q.push(mp);
        }
        //east
        a = i;
        b = j+1;
        if(in_range(a,b,n,m) && dis[a][b]>(dis[i][j]+1) && arr[a][b]==0){
            dis[a][b]=dis[i][j]+1;
            pair<ll,ll> mp = {a,b};
            q.push(mp);
        }
        //south
        a = i+1;
        b = j;
        if(in_range(a,b,n,m) && dis[a][b]>(dis[i][j]+1) && arr[a][b]==0){
            dis[a][b]=dis[i][j]+1;
            pair<ll,ll> mp = {a,b};
            q.push(mp);
        }
        //west
        a = i;
        b = j-1;
        if(in_range(a,b,n,m) && dis[a][b]>(dis[i][j]+1) && arr[a][b]==0){
            dis[a][b]=dis[i][j]+1;
            pair<ll,ll> mp = {a,b};
            q.push(mp);
        }
    }
}
int main()
{
    fastio;
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<vector<ll>> arr(n,vector<ll> (m));
        vector<string> temp(n);
        for(ll i=0;i<n;i++) cin>>temp[i];
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                if(temp[i][j]=='1') arr[i][j]=1;
                else arr[i][j]=0;
            }
        }

        vector<vector<ll>> dis(n,vector<ll> (m,INT_MAX));

        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                if(arr[i][j]){
                    bfs(arr,dis,n,m,i,j);
                }
            }
        }
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                cout<<dis[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
}   

