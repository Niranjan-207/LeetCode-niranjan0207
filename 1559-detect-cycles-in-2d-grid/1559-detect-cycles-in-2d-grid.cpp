class Solution {
public:
    vector<int> X={1,0,-1,0};
    vector<int> Y={0,1,0,-1};

    bool bfs(int x,int y,vector<vector<char>>& grid,vector<vector<bool>>& vis){
        queue<tuple<int,int,int,int>> q;
        q.push({x,y,-1,-1});
        vis[x][y]=true;
        int n=grid.size(),m=grid[0].size();
        char c=grid[x][y];
        while(!q.empty()){
            auto [cx,cy,xp,yp]=q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nx=cx+X[i];
                int ny=cy+Y[i];

                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==c ){
                    if(nx==xp && ny==yp)    continue;
                    if(vis[nx][ny]) return true;
                    vis[nx][ny]=true;
                    q.push({nx,ny,cx,cy});
                }
                    
                
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool> (m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==false){
                    if(bfs(i,j,grid,vis)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};