class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        map<int,int> mp;
        int n=matrix.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)    mp[matrix[i][j]]++;
        }
        int idx=0;
        for(auto [num,fre]:mp){
            while(fre--){
                idx++;
                if(idx==k)  return num;
            }
        }
        return -1;

    }
};