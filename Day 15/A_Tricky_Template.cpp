#include <bits/stdc++.h>
#include<string>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
    fastio;
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<string> arr(3);
        for(ll i=0;i<3;i++) cin>>arr[i];
        bool isPossible = true;
        ll cnt=0;
        for(int i=0;i<n;i++){
            if(arr[0][i]==arr[1][i]){
                if(arr[2][i]!=arr[0][i]) cnt++;
            }
            if(arr[0][i]!=arr[1][i]){
                if(arr[2][i]!=arr[0][i] && arr[2][i]!=arr[1][i]) cnt++;
            }
        }
        if(cnt==0) cout<<"NO"<<"\n";
        else cout<<"YES"<<"\n";
    }
}