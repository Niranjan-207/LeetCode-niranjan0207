class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        vector<bool> vis(n,false);
        queue<int> q;

        q.push(0);
        vis[0]=true;
        int cnt=0;
        while(!q.empty()){
            int qs=q.size();
            for(int i=0;i<qs;i++){
                int cur=q.front();
                q.pop();
                if(cur==n-1)    return cnt;

                int backward=cur-1;
                int forward=cur+1;
                if(backward>=0 && !vis[backward]){
                    q.push(backward);
                    vis[backward]=true;
                }
                if(forward<n && !vis[forward]){
                    q.push(forward);
                    vis[forward]=true;
                }

                for(int& num:mp[arr[cur]]){
                    if(num!=cur && !vis[num]){
                        q.push(num);
                        vis[num]=true;
                    }
                }
                mp[arr[cur]].clear();
            }
            cnt++;
        }
        return cnt;
    }
};