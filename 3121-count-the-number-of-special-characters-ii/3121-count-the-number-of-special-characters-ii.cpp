class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lo(26,-1),up(26,-1);
        int n=word.length();

        for(int i=0;i<n;i++){
            char c=word[i];
            if(c>='a' && c<='z'){
                lo[c-'a']=i;
            }else{
                if(up[c-'A']==-1){
                    up[c-'A']=i;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<26;i++){
            if(lo[i]!=-1 && up[i]!=-1 && lo[i]<up[i])   cnt++;
        }
        return cnt;
    }
};