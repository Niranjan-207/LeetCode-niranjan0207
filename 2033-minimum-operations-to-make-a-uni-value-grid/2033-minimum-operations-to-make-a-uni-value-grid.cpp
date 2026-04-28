class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> arr;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr.push_back(grid[i][j]);
            }
        }

        int mod=arr[0]%x;
        for(int num:arr){
            if(num%x!=mod)  return -1;
        }
        int l=arr.size();
        sort(begin(arr),end(arr));
        int med=arr[l/2];
        int cnt=0;
        for(int i=0;i<l;i++){
            cnt+=((abs(arr[i]-med))/x);
        }
        return cnt;
    }
};