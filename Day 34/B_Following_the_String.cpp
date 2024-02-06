#include <bits/stdc++.h>
#include<string>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll binarySearch(vector<ll> &cnt,ll &n,ll &k){
    
    
    ll lo=0;
    ll hi=n-1;
    ll ans;
    while(lo<=hi){
        ll mid = lo+(hi-lo)/2;
        if(cnt[mid]==k){
           ans = mid;
           hi=mid-1; 
        }
        else if(cnt[mid]<k){
            hi=mid-1;
        }else{
            lo = mid+1;
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
        vector<ll> arr(n);
        for(ll i=0;i<n;i++) cin>>arr[i];
        map<ll,vector<char>> mp;
        string str="";
        ll cnt=0;
        for(ll i=0;i<n;i++){
            if(mp[arr[i]].size()==0){
                mp[arr[i]].push_back('a');
                str+='a';
            }else{
                char ch = mp[arr[i]][mp[arr[i]].size()-1]+1;
                mp[arr[i]].push_back(ch);
                str+=ch;
            }
        }
        cout<<str<<"\n";
    }
}
// int main()
// {
//     fastio;
//     ll t=1;
//     cin>>t;
//     while(t--)
//     {
//         ll n;
//         cin>>n;
//         vector<ll> arr(n);
//         for(ll i=0;i<n;i++) cin>>arr[i];
//         vector<char> str(n);
//         map<ll,vector<char>> mp;
//         char temp = 97;
//         ll ascii = 97;
//         for(ll i=0;i<n;i++){
//             if(arr[i]==0){
//                 str[i]=temp;
//                 ll temp2 = ascii-97;
//                 mp[0].push_back(temp);
//                 temp++;
//                 ascii++;
                
//                 continue;
//             }
//             ll temp3 = binarySearch(cnt,n,arr[i]);
//             char temp4 = temp3+97;
//             str[i]=temp4;
//             cnt[temp3]++;
//         }
//         for(ll i=0;i<n;i++) cout<<str[i];
//         cout<<"\n";
//     }
// }