class Solution {

public:
    #define ll long long
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        vector<ll> ans(n,0);

        unordered_map<int,pair<ll,ll>> mp;
        for(int i=0;i<n;i++){
            int num=nums[i];
            auto& [sum,cnt]=mp[num];
            ans[i]+=((1ll*cnt*i)-sum);
            sum+=i;
            cnt++;
        }

        mp.clear();

        for(int i=n-1;i>=0;i--){
            int num=nums[i];
            auto& [sum,cnt]=mp[num];
            ans[i]+=(sum-(1ll*cnt*i));
            sum+=i;
            cnt++;
        }
        
        return ans;
    }
};