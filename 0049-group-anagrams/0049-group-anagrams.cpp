class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(string s:strs){
            string temp=s;
            sort(begin(temp),end(temp));
            mp[temp].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto [key,val]:mp){
            ans.push_back(val);
        }
        return ans;
    }
};