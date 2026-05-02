class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(begin(nums),end(nums),0);

        if(sum&1)   return false;
        int k=sum/2;
        bitset<10001> dp;
        dp[0]=1;

        for(int& num:nums){
            dp=dp|(dp<<num);
            if(dp[k])   return true;
        }
        return false;
    }
};