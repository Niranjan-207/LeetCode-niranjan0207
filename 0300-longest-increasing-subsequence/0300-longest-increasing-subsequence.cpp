class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for(int num:nums){
            if(ans.size()==0 || ans.back()<num){
                ans.push_back(num);
            }else{
                auto it=lower_bound(begin(ans),end(ans),num);
                *it=num;
            }
        }
        return ans.size();
    }
};