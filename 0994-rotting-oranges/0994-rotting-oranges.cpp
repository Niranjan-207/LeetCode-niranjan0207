class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;

        int n=grid.size(),m=grid[0].size();
        int fresh=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)    
                if(grid[i][j]==2){   
                    q.push({i,j});
                }else if(grid[i][j]==1) fresh++;
        }
        if(fresh==0)    return 0;
        vector<int> X={1,0,-1,0};
        vector<int> Y={0,1,0,-1};

        int time=-1;
        while(!q.empty()){
            
            int qs=q.size();
            while(qs--){
                auto [x,y]=q.front();
                q.pop();

                for(int i=0;i<4;i++){
                    int nx=x+X[i];
                    int ny=y+Y[i];

                    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1){
                        fresh--;
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                    }
                }
            }
            time++;
        }
        return (fresh==0?time:-1);
    }
};