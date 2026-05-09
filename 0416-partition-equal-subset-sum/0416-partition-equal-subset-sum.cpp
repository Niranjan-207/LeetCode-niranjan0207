class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(begin(nums),end(nums),0);
        if(sum&1)   return false;
        bitset<100000> dp;
        dp[0]=1;
        for(int num:nums){
            dp=dp|(dp<<num);
            if(dp[sum/2])   return true;
        }
        return false;
    }
};