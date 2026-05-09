class Solution {
public:
    static bool cmp(pair<int,string> a,pair<int,string> b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first>b.first;
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(string s:words){
            mp[s]++;
        }
        vector<pair<int,string>> arr;
        for(auto& [word,cnt]:mp){
            arr.push_back({cnt,word});
        }

        sort(begin(arr),end(arr),cmp);
        vector<string> ans;
        for(int i=0;i<k;i++)    ans.push_back(arr[i].second);
        return ans;
    }

};