class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int sum=0;
        int cnt=0;
        for(int num:nums){
            sum+=num;
            int need=sum-k;
            if(mp.contains(need)){
                cnt+=mp[need];
            }
            mp[sum]++;
        }
        return cnt;
    }
};