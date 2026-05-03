class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        set<int> se(begin(forbidden),end(forbidden));
        vector<vector<bool>> vis(50000,vector<bool>(2,false));
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0]=true;
        vis[0][1]=true;
        
        //0 ->last forward now can go backward
        //1 ->last backward now can go forward
        int steps=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto [cur,jump]=q.front();
                q.pop();

                if(cur==x)  return steps;

                int forward=cur+a;
                if(forward<50000 && !vis[forward][0] && se.find(forward)==se.end()){
                    vis[forward][0]=true;
                    q.push({forward,0});
                }

                int backward=cur-b;
                if(jump==0 && backward>=0 && !vis[backward][1] && se.find(backward)==se.end()){
                    vis[backward][1]=true;
                    q.push({backward,1});
                }

            }
            steps++;
        }
        return -1;
    }   
};