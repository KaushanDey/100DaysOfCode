#include <bits/stdc++.h>
#include<string>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define max3(a,b,c) max(max(a,b),c)
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define fr(i,n) for(ll i=0;i<n;i++)
#define in_range(x,y,r,c) (x>=0 && x<r && y>=0 && y<c)

ll Solution(string &str, ll &n,char ch){
    ll maxi = 0;
    ll cnt = 0;
    ll sum = 0;
    ll temp = 0;
    ll last=0;
    for(ll i=0;i<n;i++){
        if(str[i]==ch){
            cnt++;
            if(cnt==1){
                if(temp<last){
                    sum-=last+temp;
                }
            }
        }else{
            temp++;
            if(maxi<cnt){
                sum+=maxi;
                last = maxi;
                maxi = cnt;
                cnt=0;
            }else{
                sum+=cnt;
                last = cnt;
                cnt=0;
            }
        }
    }
    if(cnt!=0){
        if(maxi<cnt){
            sum+=maxi;
            maxi = cnt;
            cnt=0;
        }else{
            sum+=cnt;
            cnt=0;
        }
    }
    return sum;
}
int main()
{
    fastio;
    ll t=1;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        ll n = str.size();
        map<char,ll> mp;
        for(ll i=0;i<n;i++){
            mp[str[i]]++;
        }
        ll mini = INT_MAX;
        for(ll i=0;i<26;i++){
            char ch = 97+i;
            if(mp[ch]==0) continue;
            if(mp[ch]==1){
                ll op = 0;
                mini = min(mini,op);
            }else if(mp[ch]==n){
                mini = 0;
            }else{
                mini = min(mini,Solution(str,n,ch));
            }
        }
        cout<<mini<<"\n";
    }
}