class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();

        long sum=0,tot=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            tot+=(long)i*nums[i];
        }

        long ans=tot;
        for(int i=1;i<n;i++){
            tot=tot+sum-((long)n*nums[n-i]);
            ans=max(ans,tot);
        }
        return ans;
    }
};