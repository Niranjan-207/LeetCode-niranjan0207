class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int> pm(n),sm(n);
        pm[0]=nums[0];
        sm[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pm[i]=max(pm[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            sm[i]=min(sm[i+1],nums[i]);
        }
        vector<int> ans(n);
        ans[n-1]=pm[n-1];
        for(int i=n-2;i>=0;i--){
            if(pm[i]>sm[i+1]){
                ans[i]=ans[i+1];
            }else{
                ans[i]=pm[i];
            }
        }
        return ans;
    }
};