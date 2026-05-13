class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> arr(101,0);
        for(vector<int>& log:logs){
            arr[log[0]-1950]+=1;
            arr[log[1]-1950]-=1;
        }
        int ma=0;
        for(int i=1;i<=100;i++){
            arr[i]=arr[i-1]+arr[i];
            if(arr[i]>arr[ma])   ma=i;
        }
        return (1950+ma);
    }
};