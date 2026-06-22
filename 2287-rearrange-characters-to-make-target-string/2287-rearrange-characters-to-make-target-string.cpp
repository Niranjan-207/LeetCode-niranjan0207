class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> scnt(26,0);
        vector<int> tcnt(26,0);

        for(char c:s)   scnt[c-'a']++;
        for(char c:target)   tcnt[c-'a']++;

        int ans=INT_MAX;
        for(char c:target){
            ans=min(ans,scnt[c-'a']/tcnt[c-'a']);
        }
        return ans;
    }
};