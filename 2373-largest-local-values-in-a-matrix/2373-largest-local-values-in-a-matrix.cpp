class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
    
        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++){
            vector<int> temp;
            for(int j=0;j<n-2;j++){
                int gm=INT_MIN;
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        gm=max(gm,grid[i+k][j+l]);
                    }
                }
                temp.push_back(gm);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};