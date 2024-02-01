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
        string str;
        cin>>str;
        ll cnt=0;
        vector<ll> arr;
        //vector<ll> order(n,0);
        for(ll i=0;i<n;i++){
            if(str[i]=='A'){
                cnt++;
                if(str[i-1]=='B' && str[i-2]=='A'){
                    ll k = arr.size();
                    arr[k-1]++;
                }
            }
            else{
                if(str[i-1]=='A'){
                    arr.push_back(cnt);
                    cnt=0;

                }else if(str[i-1]=='B' && str[i-2]=='A'){
                    ll k = arr.size();
                    arr[k-1]++;
                }
            }
        }
        ll sum=0;
        for(ll i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        cout<<sum<<"\n";
        
    }
}