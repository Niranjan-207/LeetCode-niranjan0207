class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            int need=target-num;
            if(mp.count(need)){
                return {mp[need],i};
            }
            mp[num]=i;
        }
        return {};
    }
};