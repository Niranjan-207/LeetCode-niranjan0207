class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int> dif(2*limit+2,0);
        for(int i=0;i<(n/2);i++){
            dif[2]+=2;
            dif[2*limit+1]-=2;

            int a=nums[i];
            int b=nums[n-i-1];
            int s=a+b;

            int l=min(a,b)+1;
            int r=max(a,b)+limit;

            dif[l]+=(-1);
            dif[r+1]-=(-1);
            dif[s]+=(-1);
            dif[s+1]-=(-1);
        }

        for(int i=1;i<dif.size();i++){
            dif[i]+=dif[i-1];
        }
        return *min_element(begin(dif)+2,end(dif)-1);
    }
};