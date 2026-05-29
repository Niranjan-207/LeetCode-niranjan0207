class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans=INT_MAX;
        for(int num:nums){

            int temp=0;
            while(num>0){
                int dig=num%10;
                temp+=dig;
                num/=10;
            }
            ans=min(ans,temp);
        }
        return ans;
    }
};