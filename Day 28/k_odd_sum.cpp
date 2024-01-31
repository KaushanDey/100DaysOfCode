#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
	
	ll t;
	cin>>t;
	while(t--){
	    ll n,k;
	    cin>>n>>k;
	    if(k%2!=0){
	        for(ll i=1;i<k;i++) cout<<i<<" ";
	        for(ll i=k;i<=n;i+=2) cout<<i<<" ";
	        for(ll i=k+1;i<=n;i+=2) cout<<i<<" ";
	    }else{
	        for(ll i=1;i<k;i++) cout<<i<<" ";
	        for(ll i=k;i<=n;i+=2) cout<<i<<" ";
	        for(ll i=k+1;i<=n;i+=2) cout<<i<<" ";
	    }
	    cout<<"\n";
	    
	}

}
