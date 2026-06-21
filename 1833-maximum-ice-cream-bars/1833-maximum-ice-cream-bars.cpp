class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size();
        sort(begin(costs),end(costs));
        int cnt=0;
        int i=0;
        while(i<n && coins>0){
            if(coins>=costs[i]){
                coins-=costs[i];
                cnt++;
                
            }else   break;
            i++;
        }
        return cnt;
    }
};