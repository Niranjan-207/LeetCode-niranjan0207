class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<int,int> mp;
        for(int num:nums)   mp[num]++;

        int ans=0;
        if(mp.count(1)){
            if(mp[1]%2==0)  ans=mp[1]-1;
            else    ans=mp[1];
        }

        int ma=*max_element(begin(nums),end(nums));

        for(auto [num,fre]:mp){
            if(num==1)  continue;
            
            long long base=num;
            int cnt=0;
            while(mp[base]>=2 && !(base > INT_MAX / base) && mp[base*base]>=1 && base<ma){
                cnt+=2;
                base*=base;
            }
            cnt++;
            ans=max(ans,cnt);
        }
        return ans;
    }
};