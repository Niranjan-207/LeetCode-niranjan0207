class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.length();
        if(n%k!=0){
             s.append(k - (n % k), fill);
        }
        vector<string> ans;
        string temp="";
        int cnt=0;
        for(char& c:s){
            temp+=c;
            cnt++;
            if(cnt%k==0){
                ans.push_back(temp);
                temp="";
            }
        }
        return ans;
    }
};