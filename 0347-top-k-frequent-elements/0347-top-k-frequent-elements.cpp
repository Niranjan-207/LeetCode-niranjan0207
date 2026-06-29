class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int num:nums)   mp[num]++;

        vector<pair<int,int>> arr;
        for(auto& [num,fre]:mp){
            arr.push_back({fre,num});
        }
        sort(rbegin(arr),rend(arr));
        vector<int> ans;
        int i=0;
        while(k--){
            ans.push_back(arr[i++].second);
        }
        return ans;
    }
};