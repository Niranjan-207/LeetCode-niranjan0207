class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mi=nums[0];
        int n=nums.size();
        int dif=-1;
        for(int i=1;i<n;i++){
            if(nums[i]>mi){
                dif=max(dif,nums[i]-mi);
            }
            mi=min(mi,nums[i]);
        }
        return dif;
    }
};