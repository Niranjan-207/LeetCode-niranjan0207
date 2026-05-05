class Solution {
public:
    unordered_map<long long,int> dp;
    int solve(int idx,vector<int>& masks,int cmask){

        long long key=((long long)idx<<32)|cmask;
        if(dp.count(key))   return dp[key];
        
        int ans=__builtin_popcount(cmask);
        for(int i=idx;i<masks.size();i++){
            if((cmask & masks[i])==0) ans=max(ans,solve(i+1,masks,cmask|masks[i]));
        }
        return dp[key]=ans;
    }

    int maxLength(vector<string>& arr) {
        vector<int> masks;
        for(string s:arr){
            int mask=0;
            bool valid=true;
            for(char c:s){
                int dig=c-'a';
                if(mask&(1<<dig)){
                    valid=false;
                    break;
                }  
                mask|=(1<<dig);
            }
            if(valid)   masks.push_back(mask);
        }
        return solve(0,masks,0);
        
    }
};