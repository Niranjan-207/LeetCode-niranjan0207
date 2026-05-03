class Solution {
public:
    int n;

    int f(int idx,vector<int>& arr,int k,vector<int>& dp){
        if(idx>=n)  return 0;
        if(dp[idx]!=-1) return dp[idx];
        int ma=INT_MIN;
        int mele=0;
        for(int tk=1;tk<=k && idx+tk<=n;tk++){
            mele=max(mele,arr[idx+tk-1]);

            int cur=mele*tk+f(idx+tk,arr,k,dp);
            ma=max(cur,ma);
        }
        return dp[idx]=ma;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n=arr.size();
        vector<int> dp(n,-1);
        return f(0,arr,k,dp);
    }
};