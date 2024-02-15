#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n==1){
            cout<<1<<" "<<1<<"\n";
            continue;
        }
        if(n%2==0){
            if(n%3==0){
                ll temp = n/3;
                cout<<n/2<<" "<<temp;
            }else{
                ll temp = n/3;
                cout<<n/2<<" "<<(temp+1);
            }
            
        }else{
            ll temp = n/2;
            if(n%3==0){
                ll temp1 = n/3;
                cout<<temp+1<<" "<<temp1;
            }else{
                ll temp1 = n/3;
                cout<<temp+1<<" "<<temp1+1;
            }
            
        }
        cout<<"\n";
    }
}
