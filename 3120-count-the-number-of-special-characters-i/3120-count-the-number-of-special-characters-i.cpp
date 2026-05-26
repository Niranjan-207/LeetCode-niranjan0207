class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> lo(26,false),up(26,false);

        for(char c:word){
            if(c>='a' && c<='z')    lo[c-'a']=true;
            else    up[c-'A']=true;
        }
        int cnt=0;
        for(int i=0;i<26;i++){
            if(lo[i]&&up[i]) cnt++;
            
        }
        return cnt;

    }
};