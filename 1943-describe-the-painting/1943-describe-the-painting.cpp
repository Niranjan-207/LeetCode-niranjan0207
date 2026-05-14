class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        vector<vector<long long>> ans;
        map<int,long long> mp;
        int st=INT_MAX;;
        for(auto& segment:segments){
            st=min(st,segment[0]);
            mp[segment[0]]+=segment[2];
            mp[segment[1]]-=segment[2];
        }

        
        long long clr=mp[st];
        mp.erase(st);
        for(auto& [seg,delta]:mp){
            if(clr!=0) ans.push_back({st,seg,clr});
            st=seg;
            clr+=delta;
        }
        return ans;
    }
};