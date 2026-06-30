class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length(),m=s2.length();
        if(n>m) return false;

        vector<int> s1f(26,0),s2f(26,0);
        for(int i=0;i<n;i++){
            s1f[s1[i]-'a']++;
            s2f[s2[i]-'a']++;
        }
        
        
        if(s1f==s2f)    return true;

         for(int i=n;i<m;i++){
            s2f[s2[i]-'a']++;
            s2f[s2[i-n]-'a']--;

        
            if(s1f==s2f)    return true;
         }
        
        return false;

    }
};