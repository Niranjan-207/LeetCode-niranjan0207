class Solution {
public:

    int colorGrid(int x,int y,queue<pair<int,int>>& q,vector<vector<int>>& grid){
        queue<pair<int,int>> tq;
        tq.push({x,y});
        vector<int> X={1,0,-1,0};
        vector<int> Y={0,1,0,-1};
        q.push({x,y});
        grid[x][y]=-1;
        int n=grid.size();

        while(!q.empty()){
            int qn=q.size();
            for(int i=0;i<qn;i++){
                auto [x,y]=q.front();
                q.pop();

                for(int i=0;i<4;i++){
                    int nx=x+X[i];
                    int ny=y+Y[i];

                    if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]!=0 && grid[nx][ny]!=-1){
                        tq.push({nx,ny});
                        q.push({nx,ny});
                        grid[nx][ny]=-1;
                    }
                }
            }
        }
        
        int cnt=0;
        while(!tq.empty()){
            int tqn=tq.size();
            
            for(int i=0;i<tqn;i++){
                auto [x,y]=tq.front();
                tq.pop();

                for(int i=0;i<4;i++){
                    int nx=x+X[i];
                    int ny=y+Y[i];

                    if(nx>=0 && nx<n && ny>=0 && ny<n  && grid[nx][ny]!=-1){
                        if(grid[nx][ny]==1) return cnt;
                        tq.push({nx,ny});
                        grid[nx][ny]=-1;
                    }
                }
            }
            cnt++;
        }

        return -1;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) return colorGrid(i,j,q,grid);
            }
        }
        return -1;
    }
};