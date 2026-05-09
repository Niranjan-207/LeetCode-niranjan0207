class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};

        vector<int> ans;
        int n=matrix.size();
        int m=matrix[0].size();

        int cdir=0;
        int cr=0,cc=0;
        while(ans.size()<(n*m)){
            ans.push_back(matrix[cr][cc]);
            matrix[cr][cc]=10000;
            int nr=cr+dir[cdir][0];
            int nc=cc+dir[cdir][1];
            if(nr==n || nc==m || nc<0 || nr<0 || matrix[nr][nc]==10000)
                cdir=(cdir+1)%4;

            cr+=dir[cdir][0];
            cc+=dir[cdir][1];
        }
        return ans;
    }
};