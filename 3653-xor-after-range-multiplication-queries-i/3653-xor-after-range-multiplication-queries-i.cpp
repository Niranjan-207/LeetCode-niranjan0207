class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod=1e9+7;
        for(vector<int> q:queries){
            int l=q[0],r=q[1],k=q[2],v=q[3];
            int idx=l;
            while(idx<=r){
                nums[idx]=((1ll*nums[idx]%mod)*(1ll*v%mod))%mod;;
                idx+=k;
            }
            
        }
        int ans=0;
        for(int num:nums)   ans^=num;
        return ans;
    }
};