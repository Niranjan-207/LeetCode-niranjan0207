class Solution {
public:
int n;
    int f(int idx,vector<int>& nums,int k,vector<int>& dp){
        if(idx==n-1)  return 0;

        if(dp[idx]!=-2) return dp[idx];


        int ans=-1;
        for(int j=idx+1;j<n;j++){
            if(abs(nums[idx]-nums[j])<=k){
                int temp=f(j,nums,k,dp);

                if(temp!=-1)    ans=max(ans,temp+1);
            }
        }
        return dp[idx]=ans;
    }

    int maximumJumps(vector<int>& nums, int target) {
        n=nums.size();
        vector<int> dp(n,-2);
        return f(0,nums,target,dp);
    }
};