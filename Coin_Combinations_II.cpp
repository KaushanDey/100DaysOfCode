#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const ll MOD = 1e9+7;
 
ll noOfWays(vector<ll> &arr,ll &n,ll index,ll target,map<pair<ll,ll>,ll> &dp){
 
	
	if(target==0) return 1;
	if(index==0){
		if(target%arr[0]==0) return 1;
		else return 0;
	}
	pair<ll,ll> mp;
    mp.first = index;
    mp.second = target; 
	if(dp[mp]) return dp[mp];
	
	//take arr[index]
	ll take=0;
	if(target>=arr[index]) take = noOfWays(arr,n,index,target-arr[index],dp);
	
	// not take arr[index]
	ll notTake = noOfWays(arr,n,index-1,target,dp);
	
	return dp[mp]=((take%MOD)+(notTake%MOD))%MOD;	
}
int main(){
	ll n,x;
	cin>>n>>x;
	vector<ll> arr(n);
	for(ll i=0;i<n;i++) cin>>arr[i];
	map<pair<ll,ll>,ll> dp;
	cout<<noOfWays(arr,n,n-1,x,dp);
}
