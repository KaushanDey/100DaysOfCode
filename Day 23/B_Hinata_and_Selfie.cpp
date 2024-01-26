#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define max3(a,b,c) max(max(a,b),c)
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define fr(i,n) for(ll i=0;i<n;i++)

void Solution(vector<ld> arr,vector<ld> &k,ll n,map<pair<ld,ld>,ll> &dp){

    ld lb=arr[1]-2*pow(arr[0],0.5)*pow(arr[2],0.5);
    ld ub=arr[1]+2*pow(arr[0],0.5)*pow(arr[2],0.5);
    pair<ld,ld> mp;
    mp.first=lb;
    mp.second=ub;
    if(dp[mp]){
        if(dp[mp]!=NULL){
            cout<<"YES"<<"\n"<<dp[mp]<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }
        return;
    }

    ll cnt=0;
    ll ans=NULL;
    for(ll i=0;i<n;i++){
        if(k[i]>lb && k[i]<ub){
            cnt++;
            ans=k[i];
            break;
        }
    }
    if(cnt!=0){
        cout<<"YES"<<"\n"<<ans<<"\n";
    }else{
        cout<<"NO"<<"\n";
    }
    dp[mp]=ans;
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
        vector<ld> k(n);
        vector<vector<ld>> arr(m,vector<ld> (3));
        for(ll i=0;i<n;i++) cin>>k[i];
        for(ll i=0;i<m;i++) cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
        map<pair<ld,ld>,ll> dp;
        for(ll i=0;i<m;i++){
            Solution(arr[i],k,n,dp);
        }
    }
}