class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int l=0,n=colors.size(),r=n-1;
        for(int i=0;i<n;i++){
            if(colors[i]!=colors[n-1]){
                l=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(colors[i]!=colors[0]){
                r=i;
                break;
            }
        }
        return max(r,n-l-1);
    }
};
