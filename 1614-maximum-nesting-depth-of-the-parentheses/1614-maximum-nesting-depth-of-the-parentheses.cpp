class Solution {
public:
    int maxDepth(string s) {
        int len=0;
        int ans=0;
        for(char c:s){
            if(c=='('){  len++;ans=max(ans,len);}
            else if(c==')') len--;
            
        }
        return ans;
    }
};