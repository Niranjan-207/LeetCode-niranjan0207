class Solution {
public:
    using ull=unsigned long long;
    static const ull BASE = 1315423911ULL;

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int n=wordsContainer.size();
        int small=0;
        for(int i=0;i<n;i++){
            if(wordsContainer[i].size()<wordsContainer[small].size())   small=i;
        }

        unordered_map<ull,int> mp;
        
        for(int i=0;i<n;i++){
            string& s=wordsContainer[i];
            
            ull h=0;
            for(int j=s.length()-1;j>=0;j--){
                h=h*BASE +(ull)(s[j]-'a'+1);

                if(!mp.count(h) || wordsContainer[mp[h]].length()>s.length()){
                    mp[h]=i;
                }
            }
        }
        vector<int> ans(wordsQuery.size());

        for(int j=0;j<wordsQuery.size();j++){
            string& s=wordsQuery[j];
            int best=small;
            ull h=0;
            for(int i=s.length()-1;i>=0;i--){
                h=h*BASE +(ull)(s[i]-'a'+1);
                if(mp.count(h))  best=mp[h];
                else    break;
            }
            ans[j]=best;
        }
        return ans;
    }
};