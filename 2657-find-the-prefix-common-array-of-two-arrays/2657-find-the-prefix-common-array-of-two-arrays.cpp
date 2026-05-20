class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> mp;
        int n=A.size();
        vector<int> ans(n);
        int cnt=0;

        for(int i=0;i<n;i++){
            mp[A[i]]++;
            mp[B[i]]++;
            if(A[i]==B[i] && mp[A[i]]==2)   cnt++;
            else{
                if(mp[A[i]]==2)  cnt++;
                if(mp[B[i]]==2)  cnt++;
            }
            
            ans[i]=cnt;
        }
        return ans;
    }
};