class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> se(begin(nums),end(nums));

        int ans=0;
        for(int num:se){
            if(!se.count(num-1)){
                int cur=num+1;

                int len=1;
                while(se.count(cur++))  len++;

                ans=max(ans,len);
            }
        }
        return ans;
    }
};