class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<int> X={1,0,-1,0};
        vector<int> Y={0,1,0,-1};

        int cnt=0;
        queue<pair<int,int>> q;
        int ex=entrance[0],ey=entrance[1];
        vis[ex][ey]=true;
        q.push({ex,ey});

        while(!q.empty()){
            int qn=q.size();
            cnt++;
            for(int i=0;i<qn;i++){
                cout<<cnt<<" ";
                auto [x,y]=q.front();
                q.pop();

                if((x==0 || x==n-1 || y==0 || y==m-1) && (x!=ex || y!=ey) )    return cnt-1;

                for(int i=0;i<4;i++){
                    int nx=x+X[i];
                    int ny=y+Y[i];

                    if(nx<n && nx>=0 && ny<m && ny>=0 && !vis[nx][ny] && maze[nx][ny]=='.'){
                        q.push({nx,ny});
                        vis[nx][ny]=true;
                    }
                }
            }
            
        }
        return -1;
    }
};