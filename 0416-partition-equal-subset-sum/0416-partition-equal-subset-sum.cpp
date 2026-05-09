class Solution {
public:
    bool f(int idx,vector<int>& nums,int k,vector<vector<int>>& dp){
        if(k==0 )    return true;
        if(idx==nums.size())    return false;

        if(dp[idx][k]!=-1) return dp[idx][k];
        bool notTake=f(idx+1,nums,k,dp);

        bool take=false;
        if(nums[idx]<=k)    take=f(idx+1,nums,k-nums[idx],dp);

        return dp[idx][k]=(take||notTake);
    }

    bool canPartition(vector<int>& nums) {
        int target=accumulate(begin(nums),end(nums),0);
        if(target&1)    return false;

        vector<vector<int>> dp(nums.size()+1,vector<int> (target+1,-1));
        return f(0,nums,target/2,dp);
    }
};