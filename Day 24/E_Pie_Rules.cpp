#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// ll optimalSol(vector<ll> &arr,ll &n,ll index,ll decider,ll &sum,ll output){

//     if(output>=sum) return output;
//     if(index==0){

//         if(output+arr[index]>=sum) return output+arr[index];
//         return INT_MAX;
//     }

//     ll take=INT_MAX,notTake=INT_MAX;
//     //give the slice to the other
//     if(decider==0) notTake = optimalSol(arr,n,index-1,decider,sum,output);
//     else notTake = optimalSol(arr,n,index-1,decider,sum,output+arr[index]);
//     //eat index slice for himself
//     if(decider==0) take = optimalSol(arr,n,index-1,1,sum,output+arr[index]);
//     else take = optimalSol(arr,n,index-1,0,sum,output);

//     return min(notTake,take);
// }
void optimalSolIterative(vector<ll> &arr, ll &n){

    vector<ll> dp(n,-1); //dp[i] represents max possible sum from i to n-1 index
    ll postfixSum=arr[n-1];
    dp[n-1]=arr[n-1];
    for(ll i=n-2;i>=0;i--){
        dp[i]=max(dp[i+1],arr[i]+postfixSum-dp[i+1]);
        postfixSum+=arr[i];
    }

    cout<<postfixSum-dp[0]<<" "<<dp[0];
}
int main()
{
    fastio;
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) cin>>arr[i];
    // ll sum=0,temp=0;
    // for(ll i=0;i<n;i++) sum+=arr[i];
    // temp=sum/2;
    // ll bob = optimalSol(arr,n,n-1,0,temp,0);
    // cout<<sum-bob<<" "<<bob;
    optimalSolIterative(arr,n);
}