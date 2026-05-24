class Solution {
public:
    int dfs(int idx,int d,vector<int>& arr,vector<int>& dp){
        int n=arr.size();
        if(idx<0 || idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int ans=1;
        for(int i=idx-1;i>=max(0,idx-d);i--){
            if(arr[i]>=arr[idx]) break;
            ans=max(ans,1+dfs(i,d,arr,dp));
        }
        for(int i=idx+1;i<=min(idx+d,n-1);i++){
            if(arr[i]>=arr[idx])    break;
            ans=max(ans,1+dfs(i,d,arr,dp));
        }
        return dp[idx]=ans;
    }

    int maxJumps(vector<int>& arr, int d) {

        int n=arr.size();
        vector<int> dp(n+1,-1);
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,dfs(i,d,arr,dp));
        }
        return ans;
    }
};