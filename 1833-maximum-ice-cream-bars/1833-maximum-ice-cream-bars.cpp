class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int mi=*min_element(begin(costs),end(costs));
        int ma=*max_element(begin(costs),end(costs));

        vector<int> arr(ma-mi+1,0);
        for(int cost:costs){
            arr[cost-mi]++;
        }

        int cnt=0;
        for(int i=0;i<(ma-mi+1);i++){
            if(arr[i]==0)   continue;
            int can=min(arr[i],coins/(i+mi));

            if(can==0)  break;
            cnt+=can;
            coins-=(can*(i+mi));

        }
        return cnt;
    }
};