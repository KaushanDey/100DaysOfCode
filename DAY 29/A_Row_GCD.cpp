#include<bits/stdc++.h>
#define int long long
using namespace std;


int32_t main(){


    int n,m;
    cin>>n>>m;


    vector<int> a(n);
    vector<int> b(m);


    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];


    sort(a.begin(),a.end());


    if(n == 1){
        for(int i=0;i<m;i++) cout<<a[0]+b[i]<<" ";
        return 0;
    }


    int gcc = a[1] - a[0];
    for(int i=1;i<n;i++){
        gcc = __gcd(gcc,a[i]-a[0]);
    }


    vector<int> ans(m);
    for(int i=0;i<m;i++){
        ans[i] = __gcd(a[0]+b[i],gcc);
    }


    for(int x: ans) cout<<x<<" ";


    return 0;
}