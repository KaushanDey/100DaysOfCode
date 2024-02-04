#include <bits/stdc++.h>
#include<string>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
    fastio;
    string str;
    cin>>str;
    ll n = str.size();
    string st="";
    for(ll i=0;i<n;i++){
        if(str[i]!='.') st+=str[i];
        else{
            st="";
        }
    }
    cout<<st;
}