
#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int maxSumRecur(vector<int> &valueInHouse, int n, int index, int sum, vector<int> &dp)
{

    if (index >= n)
    {
        return sum;
    }
    if (dp[index] != -1)
    {
        return sum + dp[index];
    }
    // excluding valueInHouse[index]
    int temp1 = maxSumRecur(valueInHouse, n, index + 1, sum, dp);

    sum += valueInHouse[index];
    // including valueInHouse[index]
    int temp2 = maxSumRecur(valueInHouse, n, index + 2, sum, dp);

    return dp[index] = max(temp1, temp2);
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    vector<int> dp1(n, -1);
    vector<int> dp2(n, -1);
    if (n == 1)
    {
        return nums[0];
    }
    return max(maxSumRecur(nums, n - 1, 0, sum, dp1), maxSumRecur(nums, n, 1, sum, dp2));
}

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++) cin>>nums[i];
        cout<<rob(nums)<<"\n";
    }
}