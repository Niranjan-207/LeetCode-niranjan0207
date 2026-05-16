class Solution {
public:
    int f(int sidx,int revidx,string& s,string& rev,vector<vector<int>>& dp){
        if(sidx==s.length() || revidx==rev.length())    return 0;
        if(dp[sidx][revidx]!=-1)    return dp[sidx][revidx];
        
        if(s[sidx]==rev[revidx]){
            return dp[sidx][revidx]= 1+f(sidx+1,revidx+1,s,rev,dp);
        }
        
        return dp[sidx][revidx]=max(f(sidx+1,revidx,s,rev,dp),f(sidx,revidx+1,s,rev,dp));
    }

    int longestPalindromeSubseq(string s) {
        string rev=s;
        int n=s.length();

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        reverse(begin(s),end(s));

        return f(0,0,s,rev,dp);
    }
};