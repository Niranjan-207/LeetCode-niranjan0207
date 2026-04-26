class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long pre=nums[0];
        int i=1,n=nums.size();
        while(i<n && nums[i]>nums[i-1]){
            pre+=nums[i];
            i++;
        }i--;
        long long suf=accumulate(begin(nums),end(nums),0ll)-pre+nums[i];
        if(pre>suf) return 0;
        else if(suf>pre)    return 1;
        return -1;
    }
};