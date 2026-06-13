class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";

        for(string word:words){
            int cst=0;

            for(char c:word){
                cst+=(weights[c-'a']);
            }
            cst%=26;

            ans+=(26-cst+'a'-1);
        }
        return ans;
    }
};