class Solution {
public:
    int dp[11][2][2][1024][2];
    int solve(string s,int idx,bool tight,bool lz,int mask,bool dup){
        if(idx==s.length())  return (!lz && dup)?1:0;
        if(dp[idx][tight][lz][mask][dup]!=-1)   return dp[idx][tight][lz][mask][dup];
        int lb=0;
        int ub=tight?s[idx]-'0':9;

        int cnt=0;
        for(int dig=lb;dig<=ub;dig++){
            int nlz=(lz && dig==0);
            int ntight=(tight && dig==ub);
            
            if(nlz) cnt+=solve(s,idx+1,ntight,nlz,mask,dup);
            else{
                int nmask=mask| (1<<dig);
                bool used=(mask&(1<<dig));
                cnt+=solve(s,idx+1,ntight,nlz,nmask,dup||used);
            }
        }
        return dp[idx][tight][lz][mask][dup]=cnt;
    }

    int numDupDigitsAtMostN(int n) {
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(s,0,1,1,0,0); //idx,tight,lz,mask,dup
    }
};