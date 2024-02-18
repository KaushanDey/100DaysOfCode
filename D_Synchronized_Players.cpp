#include <bits/stdc++.h>
#include<string>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll noOfSteps(vector<vector<char>> arr, ll &n,ll i1,ll j1,ll i2,ll j2){

    if(i1==i2 && j1==j2){
        return 0;
    }
    if(arr[i1][j1]=='#' || arr[i2][j2]=='#') return 1e9;
    ll mini = 1e9;
    for(ll i=0;i<4;i++){
        for(ll j=0;j<4;j++){
            if(i==0 && i1>0) i1-=1;
            else if(i==1 && j1<(n-1)) j1+=1;
            else if(i==2 && i1<(n-1)) i1+=1;
            else if(i==3 && j1>0) j1-=1;
            if(j==0 && i2>0) i2-=1;
            else if(j==1 && j2<(n-1)) j2+=1;
            else if(j==2 && i2<(n-1)) i2+=1;
            else if(j==3 && j2>0) j2-=1;
            mini = min(mini, 1+noOfSteps(arr,n,i1,j1,i2,j2));

        }
    }
    return mini;
}
int main()
{
    fastio;
    ll n;
    cin>>n;
    vector<vector<char>> arr(n,vector<char> (n));
    ll i1,j1,i2,j2;
    ll cnt=0;
    for(ll i=0;i<n;i++){
        string str;
        cin>>str;
        for(ll j=0;j<n;j++){
             
            arr[i][j] = str[j];
            if(str[j]=='P'){
                if(cnt==0){
                    i1=i;
                    j1=j;
                    cnt++;
                }else{
                    i2=i;
                    j2=j;
                }
            }
        }
    }
    ll ans = noOfSteps(arr,n,i1,j1,i2,j2);
    if(ans>=1e9){
        cout<<-1;
        return 0;
    }
    cout<<ans;
}



