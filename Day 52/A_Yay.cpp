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
ll gcd(ll a, ll b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    fastio;
    string str;
    vector<ll> arr(26,0);
    ll t1=-1,t2=-1;
    for(ll i=0;i<str.size();i++){
        ll t = str[i]-97;
        arr[t]++;
        if(arr[t]==1){
            if(t1==-1){
                t1 = i;
            }else t2 = i;
        }
    }
    
   for(ll i=0;i<26;i++){
        if(arr[i]==1){
            char ch = 97+i;
            if(str[t1]==ch) cout<<t1+1;
            else cout<<t2+1;
        }
   }
}