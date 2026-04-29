class Solution {
public:
    int dp[11][2][2][1024];

    int solve(string s,int idx,int tight,int lz,int mask){
        if(idx==s.length()) return lz?0:1;
        if(dp[idx][tight][lz][mask]!=-1)    return dp[idx][tight][lz][mask];
        int lb=0;
        int ub=(tight?s[idx]-'0':9);

        int ans=0;
        for(int dig=lb;dig<=ub;dig++){
            int nlz=(lz && dig==0);

            if(!nlz && mask&(1<<dig))    continue;
            
            int nmask=(nlz?mask:(mask|(1<<dig)));

            ans+=solve(s,idx+1,(tight && dig==ub),nlz,nmask);
        }
        return dp[idx][tight][lz][mask]=ans;
    }

    int countSpecialNumbers(int n) {
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(s,0,1,1,0); // idx,tight,lz,mask
    }
};