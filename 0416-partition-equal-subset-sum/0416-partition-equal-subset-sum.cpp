class Solution {
public:
    bool f(int idx,vector<int>& nums,int sum,vector<vector<int>>& dp){
        if(sum==0)  return true;
        //if(idx==0 && nums[0]==sum)  return true;
        if(idx<0)  return false;

        if(dp[idx][sum]!=-1)    return dp[idx][sum];

        bool notTake=f(idx-1,nums,sum,dp);

        bool take=false;
        if(nums[idx]<=sum)  take=f(idx-1,nums,sum-nums[idx],dp);

        return dp[idx][sum]=(take || notTake);         
    }

    bool canPartition(vector<int>& nums) {
        int sum=accumulate(begin(nums),end(nums),0);
        if(sum&1)   return false;
        int target=sum/2;
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return f(n-1,nums,target,dp);//idx nums target dp
    }
};