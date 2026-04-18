class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        unordered_map<string,int> mp;
        string temp="";
        for(string word:words){
            mp[word]++;
        }
        int cnt=0;
        temp="";
        for(char c:s){
            temp+=c;
            if(mp.count(temp))  cnt+=mp[temp];
        }
        return cnt;
    }
};