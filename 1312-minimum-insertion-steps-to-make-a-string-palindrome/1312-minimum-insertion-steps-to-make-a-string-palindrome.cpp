class Solution {
public:
    int minInsertions(string s1) {
        string s2=s1;
        reverse(begin(s2),end(s2));

        int n=s1.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    ans=max(ans,dp[i][j]);
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return (n-ans);
    }
};