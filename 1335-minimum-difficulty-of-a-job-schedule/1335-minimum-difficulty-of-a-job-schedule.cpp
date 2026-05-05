class Solution {
public:
   
   
    int f(int idx,int& n,vector<int>& arr,int d,vector<vector<int>>& dp){
       if(d==1){
            return *max_element(begin(arr)+idx,end(arr));
       }
        if(dp[idx][d]!=-1)  return dp[idx][d];
       int finalValue=INT_MAX;
       int curMax=INT_MIN;
       for(int i=idx;i<=n-d;i++){
        curMax=max(curMax,arr[i]);
        int segAns=curMax+f(i+1,n,arr,d-1,dp);
        finalValue=min(finalValue,segAns);
       }
       return dp[idx][d]=finalValue;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(n<d) return -1;
        if(n==d)    return accumulate(begin(jobDifficulty),end(jobDifficulty),0);
        vector<vector<int>> dp(n,vector<int>(d+1,-1));
        return f(0,n,jobDifficulty,d,dp);   //idx,arr,cd,d    
    }
};