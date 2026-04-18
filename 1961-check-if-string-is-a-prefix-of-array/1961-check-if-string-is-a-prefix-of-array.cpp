class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string ans="";
        for(string word:words){
            ans+=word;
            if(ans.length()==s.length() && s==ans)  return true;
            if(s.find(ans)==-1) return false;
        }
        return false;
    }
};