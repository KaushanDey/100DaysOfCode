#include <bits/stdc++.h>
#include<string>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
    fastio;
    ll h,w,n;
    cin>>h>>w>>n;
    vector<vector<char>> arr(h,vector<char> (w,'.'));
    ll i=0,j=0;
    ll dir = 0;
    for(ll k=0;k<n;k++){
        if(arr[i][j]=='.'){
            arr[i][j]='#';
            dir = (dir+1)%4;
        }else{
            arr[i][j]='.';
            if(dir==0) dir = 3;
            else dir = dir-1;
        }
        if(dir==0){
            if(i==0) i=h-1;
            else i=i-1;
        }else if(dir==1){
            j = (j+1)%w;
        }else if(dir==2){
            i = (i+1)%h;
        }else if(dir==3){
            if(j==0) j=w-1;
            else j=j-1;
        }
    }
    for(ll i=0;i<h;i++){
        string st = "";
        for(ll j=0;j<w;j++){
            st+=arr[i][j];
        }
        cout<<st<<"\n";
    }
}