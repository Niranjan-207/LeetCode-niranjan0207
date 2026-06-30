class Solution {
public:
    int solve(string& s1,string& s2,int idx1,int idx2, vector<vector<int>>& dp){
        if(idx1>=s1.length() || idx2>=s2.length())  return 0;
        if(dp[idx1][idx2]!=-1)  return dp[idx1][idx2];

        if(s1[idx1]==s2[idx2]){
            return dp[idx1][idx2]=1+solve(s1,s2,idx1+1,idx2+1,dp);
        }
        return dp[idx1][idx2]=max(solve(s1,s2,idx1+1,idx2,dp),solve(s1,s2,idx1,idx2+1,dp));
    }

    int minDistance(string word1, string word2) {
        int n=word1.length(),m=word2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int st=solve(word1,word2,0,0,dp);

        return (n+m-(2*st));
    }
};