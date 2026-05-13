class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> mp;
        for(vector<int>& trip:trips){
            int n=trip[0],l=trip[1],r=trip[2];
            mp[l]+=n;
            mp[r]-=n;
        }
        int cap=0;
        for(auto& [ran,delta]:mp){
            cap+=delta;
            if(cap>capacity)    return false;
        }
        return true;
    }
};