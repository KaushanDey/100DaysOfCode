#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void luckyNumbers(vector<ll> &p,ll start,ll index,ll moves,bool &isLucky){

    // if(dp[index]!=-1){
    //     if(moves%2==0 && dp[index]==1){
    //         return;
    //     }else if(moves%2==0 && dp[index]==0){
    //         isLucky=false;
    //         return;
    //     }else if(moves%2!=0 && dp[index]==1){
    //         isLucky=false;
    //         return;
    //     }else if(moves%2!=0 && dp[index]==0){
    //         return;
    //     }
    // }
    moves+=1;
    ll cnt = 0;
    for(ll i=index-1;i>=0;i--){
        if(p[i]<p[index]){
            cnt++;
            luckyNumbers(p,start,i,moves,isLucky);
        }
    }

    if(cnt==0){
        if(moves%2==0){
            isLucky=false;
            return;
        }
    }

}

ll luckyNumbersIterative(vector<ll> &p, ll n, vector<ll> &dp){

    ll ans=0;
    dp[0]=0;
    for(ll i=1;i<n;i++){
        for(ll j=0;j<i;j++){
            
            if(p[j]<p[i]){
                if(dp[j]==1){
                    dp[i]=0;
                    break;
                }
                if(dp[j]==0){
                    ans++;
                    dp[i]=1;
                    break;
                }
            }
        }
    }
    return ans;
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
        vector<ll> p(n);
        for(ll i=0;i<n;i++) cin>>p[i];
        bool isLucky = true;
        ll moves=1;
        ll ans=0;
        vector<ll> dp(n,-1);
        for(ll i=n-1;i>=0;i--){
            luckyNumbers(p,i,i,moves,isLucky);
            if(isLucky){
                ans++;
            }
            moves=1;
            isLucky = true;
        }
        cout<<ans<<"\n";
        //cout<<luckyNumbersIterative(p,n,dp)<<"\n";
    }
}