class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long pro=1;
        int cnt0=0;
        for(int num:nums){
            if(num==0)  cnt0++;
            else    pro*=num;
        }

        int n=nums.size();
        vector<int> ans(n,0);
        if(cnt0>1){
            return ans;
        }

        for(int i=0;i<n;i++){
            if(cnt0==1 && nums[i]!=0){
                ans[i]=0;
            }
            else if(nums[i]==0){
                ans[i]=pro;
            }else{
                ans[i]=pro/nums[i];
            }
        }
        return ans;
    }
};