class Solution {
public:
    int f(string& s1,string& s2,int idx1,int idx2,vector<vector<int>>& dp){

        if(idx1<0 || idx2<0)    return 0;
        if(dp[idx1][idx2]!=-1)  return dp[idx1][idx2];
        int match=0;
        if(s1[idx1]==s2[idx2]){
            match=1+f(s1,s2,idx1-1,idx2-1,dp);
        }
        int notMatch=max({f(s1,s2,idx1,idx2-1,dp),f(s1,s2,idx1-1,idx2,dp)});

        return dp[idx1][idx2]=max(match,notMatch);
    }

    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.length(),m=s2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //return f(text1,text2,n-1,m-1,dp);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};