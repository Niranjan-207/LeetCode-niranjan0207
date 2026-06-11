class Solution {
public:

    int pow(long long a,long long b){
        int mod=(int)(1e9+7);
        long long res=1;
        while(b>0){
            if(b&1) res=(res*a)%mod;

            a=(a*a)%mod;
            b>>=1;
        }
        return res;
    }


    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>> graph(n+1);

        for(vector<int>& edge:edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(n+1,false);
        int depth=0;

        queue<int> q;
        q.push(1);
        vis[1]=true;

        while(!q.empty()){
            int qs=q.size();
            while(qs--){
                int cur=q.front();
                q.pop();

                for(int& ch:graph[cur]){
                    if(!vis[ch]){
                        vis[ch]=true;
                        q.push(ch);
                    }
                }
            }
            depth++;
        }
        return pow(2,depth-2);
    }
};