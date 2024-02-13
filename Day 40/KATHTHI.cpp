#include <bits/stdc++.h>
#include<string>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define in_range(x,y,r,c) (x>=0 && x<r && y>=0 && y<c)

void bfs(vector<vector<char>> &arr, vector<vector<ll>> &killed, ll &r, ll &c){

    deque<pair<ll,ll>> q;
    pair<ll,ll> mp = {0,0};
    killed[0][0]=0;
    q.push_front(mp);
    ll a,b;
    while(!q.empty()){
        pair<ll,ll> front = q.front();
        ll i = front.first;
        ll j = front.second;
        q.pop_front();
        //north
        a = i-1;
        b = j;
        if(in_range(a,b,r,c)){
            if(arr[i][j]==arr[a][b] && killed[a][b]>killed[i][j]){
                pair<ll,ll> mp = {a,b};
                q.push_front(mp);
                killed[a][b]=killed[i][j];
            }else if(arr[i][j]!=arr[a][b] && killed[a][b]>(killed[i][j]+1)){
                pair<ll,ll> mp = {a,b};
                q.push_back(mp);
                killed[a][b]=killed[i][j]+1;
            }
        }
        //east
        a = i;
        b = j+1;
        if(in_range(a,b,r,c)){
            if(arr[i][j]==arr[a][b] && killed[a][b]>killed[i][j]){
                pair<ll,ll> mp = {a,b};
                q.push_front(mp);
                killed[a][b]=killed[i][j];
            }else if(arr[i][j]!=arr[a][b] && killed[a][b]>(killed[i][j]+1)){
                pair<ll,ll> mp = {a,b};
                q.push_back(mp);
                killed[a][b]=killed[i][j]+1;
            }
        }
        //south
        a = i+1;
        b = j;
        if(in_range(a,b,r,c)){
            if(arr[i][j]==arr[a][b] && killed[a][b]>killed[i][j]){
                pair<ll,ll> mp = {a,b};
                q.push_front(mp);
                killed[a][b]=killed[i][j];
            }else if(arr[i][j]!=arr[a][b] && killed[a][b]>(killed[i][j]+1)){
                pair<ll,ll> mp = {a,b};
                q.push_back(mp);
                killed[a][b]=killed[i][j]+1;
            }
        }
        //west
        a = i;
        b = j-1;
        if(in_range(a,b,r,c)){
            if(arr[i][j]==arr[a][b] && killed[a][b]>killed[i][j]){
                pair<ll,ll> mp = {a,b};
                q.push_front(mp);
                killed[a][b]=killed[i][j];
            }else if(arr[i][j]!=arr[a][b] && killed[a][b]>(killed[i][j]+1)){
                pair<ll,ll> mp = {a,b};
                q.push_back(mp);
                killed[a][b]=killed[i][j]+1;
            }
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
        ll r,c;
        cin>>r>>c;
        vector<vector<char>> arr(r, vector<char> (c));
        for(ll i=0;i<r;i++){
            for(ll j=0;j<c;j++){
                cin>>arr[i][j];
            }
        }

        vector<vector<ll>> killed(r,vector<ll> (c,INT_MAX));
        bfs(arr,killed,r,c);
        cout<<killed[r-1][c-1]<<"\n";

    }
}