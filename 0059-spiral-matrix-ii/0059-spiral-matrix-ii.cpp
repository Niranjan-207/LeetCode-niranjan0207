class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>> ans(n,vector<int>(n,0));

        int curDir=0;
        int num=1;
        int r=0,c=0;

        while(num<=(n*n)){
            ans[r][c]=num++;
            
            int nr=r+dir[curDir][0];
            int nc=c+dir[curDir][1];
            if(nr<0 || nr>=n || nc<0 || nc>=n ||ans[nr][nc]!=0){
                curDir=(curDir+1)%4;
            }
            r=r+dir[curDir][0];
            c=c+dir[curDir][1];
        }
        return ans;
    }
};