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

ll Solution(vector<ll> &a,vector<ll> &b, ll &n,ll l, ll i, vector<ll> vis, vector<ll> &dp){

    if(dp[l]!=-1) return dp[l];
    ll maxi = 0;
    for(ll j=0;j<n;j++){
        if(j==i || vis[j]==1) continue;
        ll take = 0;
        ll t = abs(b[j]-b[i])+a[j];
        if(l>t){
            vis[j]=1;
            take = 1+Solution(a,b,n,l-t,j,vis,dp);
            vis[j]=0;
        }if(l==t){
            take = 1;
        }
        if(l<t){
            take = 0;
        }
        maxi = max(maxi,take);
    }
    return dp[l] = maxi;

}
int main()
{
    fastio;
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll n,l;
        cin>>n>>l;
        vector<ll> a(n), b(n);
        for(ll i=0;i<n;i++){
            cin>>a[i]>>b[i];
        }
        ll maxi = 0;
        vector<ll> dp(l+1,-1);
        vector<ll> vis(n,0);
        for(ll i=0;i<n;i++){
            ll take = 0;
            if(l>a[i]){
                vis[i]=1;
                maxi = max(maxi,1+Solution(a,b,n,l-a[i],i,vis,dp));
                vis[i]=0;
            }
            if(l==a[i]){
                take = 1;
                maxi = max(maxi,take);
            }
            if(l<a[i]){
                take = 0;
                maxi = max(maxi,take);
            }
            
        }
        cout<<maxi<<"\n";
    }
}
