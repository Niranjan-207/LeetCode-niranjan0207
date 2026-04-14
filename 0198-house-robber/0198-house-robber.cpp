class Solution {
public:
    int solve(vector<int> nums){
        int n=nums.size();
        vector<int> dp(n);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1) take+=dp[i-2];

            int notTake=dp[i-1];
            dp[i]=max(take,notTake);
        }
        return dp[n-1];

    }

    int rob(vector<int>& nums) {
        return solve(nums);
    }
};