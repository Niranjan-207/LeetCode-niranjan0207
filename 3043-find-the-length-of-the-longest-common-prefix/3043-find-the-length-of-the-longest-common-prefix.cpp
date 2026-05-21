class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<string> se;
        for(int num:arr1){
            string s=to_string(num);
            string temp="";
            for(char c:s){
                temp+=c;
                se.insert(temp);
            }
        }
        int ans=0;
        for(int num:arr2){
            string s=to_string(num);
            string temp="";
            for(char c:s){
                temp+=c;
                if(se.count(temp))  ans=max(ans,(int)temp.length());
            }
            
        }
        return ans;
    }
};