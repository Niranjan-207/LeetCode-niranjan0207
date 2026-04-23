class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> mp;
        for(int num:nums)   mp[num]+=num;
        vector<int> arr;
        for(auto& [a,b]:mp) arr.push_back(a);
        
        int m=arr.size();
        vector<int> dp(m,0);
        dp[0]=mp[arr[0]];
        for(int i=1;i<m;i++){
            int take=mp[arr[i]];
            int dont=dp[i-1];

            if(arr[i-1]+1==arr[i]){
                if(i-2>=0)   take+=dp[i-2];
            }else{
                take+=dp[i-1];
            }
            
            dp[i]=max(take,dont);
        }
        return dp[m-1];
    }
};