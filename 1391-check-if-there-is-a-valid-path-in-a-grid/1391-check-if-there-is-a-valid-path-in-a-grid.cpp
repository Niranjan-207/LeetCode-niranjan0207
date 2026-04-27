class Solution {
public:

    vector<vector<pair<int,int>>> dir = {
    {},
    {{0,-1},{0,1}},
    {{-1,0},{1,0}},
    {{0,-1},{1,0}},
    {{0,1},{1,0}},
    {{0,-1},{-1,0}},
    {{0,1},{-1,0}}
};


    bool hasValidPath(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<int,int>> q;

        q.push({0,0});
        vis[0][0]=true;

        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();

            
            if(x==n-1 && y==m-1)    return true;

            for(auto& [dx,dy]:dir[grid[x][y]]){
                int nx=x+dx,ny=y+dy;
                if(nx>=n || nx<0 || ny>=m || ny<0 || vis[nx][ny]) continue;
                for(auto& [bx,by]:dir[grid[nx][ny]]){
                    if(nx+bx==x && ny+by==y){
                        vis[nx][ny]=true;
                        q.push({nx,ny});
                        break;
                    }
                }
            }
        }
        return false;

    }
};