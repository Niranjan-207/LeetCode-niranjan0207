class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==1 && grid[0][0]==1)    return -1;
        if(n==1 && grid[0][0]==0)    return 1;
        if(grid[0][0]==1 || grid[n-1][n-1]==1)  return -1;
        vector<int> X={1,1,0,-1,-1,-1,0,1};

        vector<int> Y={0,1,1,1,0,-1,-1,-1};
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=-1;
        int cnt=1;
        while(!q.empty()){
            int qn=q.size();
            cnt++;
            for(int i=0;i<qn;i++){
                auto [x,y]=q.front();
                q.pop();

                for(int i=0;i<8;i++){
                    int nx=x+X[i];
                    int ny=y+Y[i];

                    if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]!=-1 && grid[nx][ny]!=1){
                        if(nx==n-1 && ny==n-1)  return cnt;
                        q.push({nx,ny});
                        grid[nx][ny]=-1;
                    }
                }
            }
            
        }
        return -1;
    }
};