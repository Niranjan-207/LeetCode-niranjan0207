class Solution {
public:
    string check(string& s,int l,int r){
        int n=s.length();
        while(l>=0 && r<n && s[l]==s[r]){
            l--;r++;
        }
        return s.substr(l+1,r-l-1);
    }

    string longestPalindrome(string s) {
        string ans="";
        int n=s.length();

        for(int i=0;i<n;i++){
            string cur=check(s,i,i);
            if(cur.length()>ans.length()) ans=cur;

            cur=check(s,i,i+1);
            if(cur.length()>ans.length()) ans=cur;
        }
        return ans;
    }
};