class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int cnt=0;
        for(string& word:words){
            if(s.length()>=word.length() && s.compare(0,word.size(),word)==0){
                cnt++;
            }
        }
        return cnt;
    }
};