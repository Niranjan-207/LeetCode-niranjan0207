class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& res) {
        res.push_back({1,0});
        res.push_back({n,n-1});
        sort(begin(res),end(res));

        int m=res.size();

        for(int i=1;i<m;i++){
            int h=res[i][0]-res[i-1][0];
            res[i][1]=min(res[i][1],res[i-1][1]+h);
        }

        for(int i=m-2;i>=0;i--){
            int h=res[i+1][0]-res[i][0];
            res[i][1]=min(res[i][1],res[i+1][1]+h);
        }
        int ans=0;
        for(int i=1;i<m;i++){
            int lid=res[i-1][0];
            int lh=res[i-1][1];

            int cid=res[i][0];
            int ch=res[i][1];

            int d=cid-lid;
            int hdif=abs(ch-lh);

            int peak=max(ch,lh)+(d-hdif)/2;
            ans=max(ans,peak);
        }
        return ans;

    }
};