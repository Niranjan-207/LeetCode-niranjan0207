class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n,0);

        for(vector<int> e:edges){
            indegree[e[0]]++;
            graph[e[1]].push_back(e[0]);
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)  q.push(i);
        }

        int completed=0;
        while(!q.empty()){
            int cur=q.front();
            q.pop();

            completed++;

            for(int child:graph[cur]){
                indegree[child]--;
                if(indegree[child]==0){
                    q.push(child);
                }
            }
        }
        return completed==n;
    }
};