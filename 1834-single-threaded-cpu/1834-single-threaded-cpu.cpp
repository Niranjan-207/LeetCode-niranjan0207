class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        vector<vector<int>> arr;
        for(int i=0;i<n;i++)    arr.push_back({tasks[i][0],tasks[i][1],i});
        sort(begin(arr),end(arr));

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;
        vector<int> ans;

        int idx=0;
        long long ctim=0;
        
        while(idx<n || !pq.empty()){
            if(pq.empty() && ctim<arr[idx][0]){
                ctim=arr[idx][0];
            }
            
            while(idx<n && arr[idx][0]<=ctim){
                pq.push({arr[idx][1],arr[idx][2]});
                idx++;
            }
            auto [processTime,pidx]=pq.top();
            pq.pop();

            ctim+=processTime;
            ans.push_back(pidx);
        }
        return ans;
    }
};