class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string temp="";
        int n=s.length();

        for(char& c:s){
            if(c!='-'){
                if(c>='a' && c<='z')    c^=32;
                temp+=c;
            }
        }

        reverse(begin(temp),end(temp));
        string ans="";
        int cnt=0;
        for(char c:temp){
            if(cnt==k){
                ans+='-';
                cnt=0;
            }
            cnt++;
            ans+=c;
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};