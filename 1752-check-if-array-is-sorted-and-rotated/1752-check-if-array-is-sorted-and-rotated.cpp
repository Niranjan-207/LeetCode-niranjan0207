class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1])   cnt++;
            if(cnt==2)  return false;
        }
        if(cnt==1) return (nums[0]>=nums[n-1]);
        return true;
    }
};