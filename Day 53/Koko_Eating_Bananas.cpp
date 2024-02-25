#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class Solution {
public:
    int minEatingSpeed(vector<ll>& piles, ll h) {
        ll maxi = *max_element(piles.begin(),piles.end());
        ll lo = 1;
        ll hi = maxi;
        ll ans = maxi;
        while(lo<=hi){
            ll mid = lo + (hi-lo)/2;
            ll t = 0;
            for(ll i=0;i<piles.size();i++){
                if(piles[i]%mid==0) t+=piles[i]/mid;
                else t+=piles[i]/mid+1;
            }
            if(h>=t){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }

        return ans;
    }
};

int main(){
    ll n,h;
    cin>>n;
    vector<ll> piles(n);
    for(ll i=0;i<n;i++) cin>>piles[i];
    cin>>h;
    Solution ans = Solution();
    cout<<ans.minEatingSpeed(piles,h);
}