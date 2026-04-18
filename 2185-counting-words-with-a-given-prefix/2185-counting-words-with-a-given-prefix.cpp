class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt=0;
        for(string& word:words){
            if(word.length()>=pref.length() && word.starts_with(pref))   cnt++;
        }
        return cnt;
    }
};