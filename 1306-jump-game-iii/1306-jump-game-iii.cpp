class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        //if(start==0)    return true;
        
        int n=arr.size();
        queue<int> q;
        vector<bool> vis(n,false);

        q.push(start);
        vis[start]=true;

        while(!q.empty()){
            int cur=q.front();
            q.pop();
            if(arr[cur]==0)  return true;

            int backward=cur-arr[cur];
            int forward=cur+arr[cur];

            if(backward>=0 && !vis[backward]){
                q.push(backward);
                vis[backward]=true;
            }

            if(forward<n && !vis[forward]){
                q.push(forward);
                vis[forward]=true;
            }
        }
        return false;
    }
};