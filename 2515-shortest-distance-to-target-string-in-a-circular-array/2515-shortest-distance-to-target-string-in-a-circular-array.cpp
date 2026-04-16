class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans=INT_MAX,n=words.size();
        for(int i=0;i<n;i++){
            if(words[i]==target){
                int dif=abs(i-startIndex);
                int dis=min(dif,n-dif);
                ans=min(ans,dis);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};