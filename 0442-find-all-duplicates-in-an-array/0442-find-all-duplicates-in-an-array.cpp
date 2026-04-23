class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int i=0,n=nums.size();
        while(i<n){
            int actual=nums[i]-1;
            if(nums[actual]!=nums[i]){
                swap(nums[actual],nums[i]);
            }else{
                i++;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(i+1!=nums[i])    ans.push_back(nums[i]);
        }
        return ans;
    }
};