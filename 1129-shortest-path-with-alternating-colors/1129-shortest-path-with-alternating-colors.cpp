class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> graph(n);     //0 ->red  1->green
        for(auto node:redEdges){
            graph[node[0]].push_back({node[1],0});
        }
        for(auto node:blueEdges){
            graph[node[0]].push_back({node[1],1});
        }

        vector<vector<bool>> vis(n,vector<bool>(2,false));
        queue<pair<int,int>> q;
        q.push({0,1});
        q.push({0,0});

        vis[0][0]=true;
        vis[0][1]=true;
        int steps=0;
        vector<int> dis(n,-1);
        while(!q.empty()){
            int sz=q.size();

            while(sz--){
                auto [cur,col]=q.front();
                q.pop();

                if(dis[cur]==-1)    dis[cur]=steps;

                for(auto& [child,ccol]:graph[cur]){
                    if(vis[child][ccol] || col==ccol)   continue;

                    vis[child][ccol]=true;
                    q.push({child,ccol});
                }

            }
            steps++;
        }
        return dis;
    }
};