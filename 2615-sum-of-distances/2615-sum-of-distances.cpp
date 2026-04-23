class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        vector<long long> ans(n,0);

        unordered_map<int,pair<long long,int>> mp;
        for(int i=0;i<n;i++){
            int num=nums[i];

            if(mp.find(num)==mp.end()){
                mp[num]={i,1};
            }else{
                long long sum=mp[num].first;
                int cnt=mp[num].second;
                ans[i]+=((1ll*cnt*i)-sum);
                mp[num].first+=i;
                mp[num].second++;
            }
        }
        mp.clear();
        for(int i=n-1;i>=0;i--){
            int num=nums[i];

            if(mp.find(num)==mp.end()){
                mp[num]={i,1};
            }else{
                long long sum=mp[num].first;
                int cnt=mp[num].second;
                ans[i]+=(sum-(1ll*cnt*i));
                mp[num].first+=i;
                mp[num].second++;
            }
        }
        return ans;
    }
};