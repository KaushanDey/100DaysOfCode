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

string Reverse(string &str){
    string temp1 = "";
    string temp2 = "";
    for(ll i=0;i<str.size();i++){
        temp1+=str[i];
    }
    for(ll i=str.size()-1;i>=0;i--){
        temp2+=str[i];
    }
    return temp2+temp1;
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
        string str;
        cin>>str;
        ll t = str.size();
        ll i=0,j=t-1;
        while(str[i]==str[j] && i<=j){
            i++;
            j--;
        }
        if(i>j){
            cout<<str<<"\n";
            continue;
        }
        if(str[i]<str[j]){
            cout<<str<<"\n";
            continue;
        }
        if(str[i]>str[j]){
            cout<<Reverse(str)<<"\n";
            continue;
        }
    }
}