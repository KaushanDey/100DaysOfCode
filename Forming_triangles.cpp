#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll Length(ll pow){
    ll ans=1;
    for(ll i=1;i<=pow;i++){
        ans*=2;
    }
    return ans;
}
ll noOfWays(vector<ll> &arr,ll n,ll index,vector<ll> output,ll sum,map<pair<ll,ll>,ll> &dp){

    if(output.size()==3){
        if(output[0]+output[1]>output[2] && output[0]+output[2]>output[1] && output[1]+output[2]>output[0]) return 1;
        return 0;
    }
    if(index>=n) return 0;

    pair<ll,ll> mp;
    mp.first=index;
    mp.second=sum;
    if(dp[mp]) return dp[mp];
    //not take index
    ll notTake = noOfWays(arr,n,index+1,output,sum,dp);
    //take index
    ll temp=Length(arr[index]);
    output.push_back(temp);
    ll take = noOfWays(arr,n,index+1,output,sum+temp,dp);

    return dp[mp]=(take+notTake);
    
}

int main()
{
    fastio;
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++) cin>>arr[i];
        vector<ll> output;
        map<pair<ll,ll>,ll> dp;
        ll sum=0;
        cout<<noOfWays(arr,n,0,output,sum,dp)<<"\n";
    }
}