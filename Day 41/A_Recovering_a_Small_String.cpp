#include <bits/stdc++.h>
#include<string>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define max3(a,b,c) max(max(a,b),c)
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define fr(i,n) for(ll i=0;i<n;i++)
ll gcd(ll a, ll b)
{
    return b==0?a:gcd(b,a%b);
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
        ll temp = n/26;
        if(temp==0){
            char ch = 97+n-3;
            cout<<"aa"<<ch<<"\n";
        }else if(temp==1){
            ll t1 = n%26;
            if(t1==0){
                cout<<"aax\n";
                continue;
            }else if(t1==1){
                cout<<"aay\n";
                continue;
            }
            char ch = 97+t1-2;
            cout<<"a"<<ch<<"z"<<"\n";
        }else if(temp==2){
            ll t1 = n%26;
            if(t1==0){
                cout<<"ayz\n";
                continue;
            }
            
            char ch = 97+t1-1;
            cout<<ch<<"zz"<<"\n";
        }else if(temp==3){
            cout<<"zzz"<<"\n";
        }
    }
}