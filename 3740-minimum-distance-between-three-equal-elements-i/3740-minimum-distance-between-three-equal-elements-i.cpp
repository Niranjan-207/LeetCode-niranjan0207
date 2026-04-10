class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i!=j && j!=k && k!=i && nums[i]==nums[j] && nums[j]==nums[k] && nums[k]==nums[i]){
                        ans=min(ans,abs(i-j)+abs(j-k)+abs(k-i));
                    }
                }
            }
        }
            if(ans==INT_MAX) return -1;
        return ans;
    }
    
};