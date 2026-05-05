class Solution {
public:
    unordered_map<string,int> dp;
    string encode(int idx,int ma,int cd){
        return (to_string(idx)+'#'+to_string(ma)+'#'+to_string(cd));
    }
    int f(int idx,int ma,vector<int>& arr,int cd,int d){
        if(cd>d)    return 1e9;
        if(idx==arr.size() && cd==d)    return ma;
        if(idx==arr.size()) return 1e9;

        string key=encode(idx,ma,cd);
        if(dp.count(key)) return dp[key];
        int newDay=ma+f(idx+1,arr[idx],arr,cd+1,d);
        int sameDay=f(idx+1,max(ma,arr[idx]),arr,cd,d);
        return dp[key]=min(newDay,sameDay);
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(n<d) return -1;
        if(n==d)    return accumulate(begin(jobDifficulty),end(jobDifficulty),0);
        
        return f(1,jobDifficulty[0],jobDifficulty,1,d);   //idx,max,arr,cd,d    
    }
};