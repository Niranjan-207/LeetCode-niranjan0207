class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int i=0,n=nums.size();

        while(i<n){
            int act=nums[i];
            if(nums[i]!=nums[act]){
                swap(nums[i],nums[act]);
            }else{
                i++;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]!=i)  ans.push_back(nums[i]);
        }
        return ans;
    }
};