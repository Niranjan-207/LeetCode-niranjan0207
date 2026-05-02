class Solution {
public:
    int f(int idx,int target,vector<int>& nums,vector<vector<int>>& dp,int& tot){
        if(idx==0){
            if(target==0 && nums[idx]==0)   return 2;
            if(target==nums[0] || target==-nums[0]) return 1;
            return 0;
        }
        if (target > tot || target < -tot) return 0;

        if(dp[idx][target+tot]!=-1) return dp[idx][target+tot];

        int m=f(idx-1,target-nums[idx],nums,dp,tot);
        int p=f(idx-1,target+nums[idx],nums,dp,tot);

        return dp[idx][target+tot]=m+p;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int tot=accumulate(begin(nums),end(nums),0);
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int> (2*tot+1,-1));
        return f(n-1,target,nums,dp,tot);
    }
};