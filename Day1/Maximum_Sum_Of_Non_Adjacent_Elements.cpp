#include <bits/stdc++.h>
using namespace std;

int maxSumRecursion(vector<int> &nums,int index,int n,int sum,int ans, vector<int> &dp){

    if(index>=n){
        return sum;
    }
    if(dp[index]!=-1) return sum+dp[index];
    //excluding nums[index]
    int temp1 = maxSumRecursion(nums,index+1,n,sum,ans,dp);
    //including nums[index]
    sum+=nums[index];
    int temp2=maxSumRecursion(nums,index+2,n,sum,ans,dp);

    return dp[index] = max(temp1,temp2);

}
int maximumNonAdjacentSum(vector<int> &nums){
    int index=0;
    int n = nums.size();
    int ans=0;
    int sum=0;
    vector<int> dp(n,-1);
    return maxSumRecursion(nums,index,n,sum,ans,dp);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++) cin>>nums[i];
        cout<<maximumNonAdjacentSum(nums)<<"\n";
    }
}