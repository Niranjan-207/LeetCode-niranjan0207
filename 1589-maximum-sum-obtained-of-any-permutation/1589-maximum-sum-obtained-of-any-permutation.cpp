class Solution {
public:
    

    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int mod=1e9+7;
        int n=nums.size();
        vector<int> fre(n);
        for(vector<int> request:requests){
            fre[request[0]]+=1;
            if(request[1]+1<n){
                fre[request[1]+1]-=1;
            }
        }
        sort(rbegin(nums),rend(nums));
        for(int i=1;i<n;i++){
            fre[i]=fre[i-1]+fre[i];
        }
        sort(rbegin(fre),rend(fre));
        long long sum=0;

        for(int i=0;i<n;i++){
            sum=(sum+(fre[i]*1ll*nums[i])%mod)%mod;
        }

        return (int)sum;
        
    }
};