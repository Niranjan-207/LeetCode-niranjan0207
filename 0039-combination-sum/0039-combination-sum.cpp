class Solution {
public:
    void solve(int idx,int sum,vector<int> temp,vector<vector<int>>& ans,vector<int>& candidates, int& target){
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        if(sum>target || idx==candidates.size())  return;
        temp.push_back(candidates[idx]);
        solve(idx,sum+candidates[idx],temp,ans,candidates,target);
        temp.pop_back();

        solve(idx+1,sum,temp,ans,candidates,target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,0,temp,ans,candidates,target);
        return ans;
    }
};