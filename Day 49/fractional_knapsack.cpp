#include <bits/stdc++.h>
#include<string>
using namespace std;
#define ll long long int
#define ld long double

class Object{
	
	public:
		ld ratio;
		ld weight;
		Object(ld ratio, ld weight){
			this->ratio = ratio;
			this->weight = weight;
		}
};
ld maxProfit(vector<Object> &arr,ld m, ld &n){

    ll i=0;
    ll profit = 0;
    cout<<"The weight of each taken:\n";
    while(m>0 && i<n){
    	if(arr[i].ratio<0){
    		i++;
    		continue;
		}
        if(m>=(arr[i].weight)){
            profit+=arr[i].ratio*arr[i].weight;
            cout<<i+1<<" "<<arr[i].weight;
            m-=arr[i].weight;
            i++;
        }else{
            profit+=arr[i].ratio*m;
            cout<<i+1<<" "<<m;
            m=0;
        }
        cout<<"\n";
    }

    return profit;

}
bool compare(Object a,Object b){
	
	return (a.ratio>b.ratio);
}
int main()
{
    ld n,m;
    cout<<"Enter the number of objects: ";
    cin>>n;
    cout<<"Enter maximum weight allowed: ";
    cin>>m;
    cout<<"Enter the profit and weight of each object with space between the two inputs:\n";
    vector<ld> p(n),w(n);
    for(ll i=0;i<n;i++){
    	ld x,y;
    	cin>>x>>y;
    	if(y<=0){
    		cout<<"Weight has to be positive";
    		return 0;
		}
		p[i]=x;
		w[i]=y;
	}
    vector<Object> arr;
    for(ll i=0;i<n;i++){
        ld temp = p[i]/w[i];
        Object obj = Object(temp,w[i]);
        arr.push_back(obj);
    }
    sort(arr.begin(),arr.end(),compare);
    cout<<"The profit ratios are: ";
    for(ll i=0;i<n;i++){
    	cout<<arr[i].ratio<<" ";
	}
	cout<<"\n";
    
    ld temp = maxProfit(arr,m,n);
    cout<<"\n";
    cout<<"Maximum profit = ";
    cout<<temp;
}
