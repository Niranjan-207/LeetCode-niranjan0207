class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        vector<int> pre(n);
        for(auto& [num,list]:mp){
            int m=list.size();
            if(m==1){
                pre[list[0]]=-1;
                continue;
            }

            for(int i=0;i<m;i++){
                int cur=list[i];

                int prev=list[(i-1+m)%m];
                int next=list[(i+1)%m];

                int pdif=abs(cur-prev);
                pdif=min(pdif,n-pdif);

                int ndif=abs(cur-next);
                ndif=min(ndif,n-ndif);

                pre[cur]=min(pdif,ndif);
            }
        }

        vector<int> ans;
        for(int q:queries){
            ans.push_back(pre[q]);
        }
        return ans;

    }
};