class Solution {
public:
    #define ll long long
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<ll,ll> mp;
        
        ll cumSum=0;
        mp[0]=1;

        ll validPoints=0,ans=0;

        for(int num:nums){
            if(num==target){
                validPoints+=mp[cumSum];
                cumSum++;
            }else{
                cumSum-=1;
                validPoints-=mp[cumSum];
            }
            mp[cumSum]++;
            ans+=validPoints;
        }
        return ans;

        
    }
};