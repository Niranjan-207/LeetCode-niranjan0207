class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int cnt=0;
        for(int num:nums){
            while(num>0){
                int dig=num%10;
                if(dig==digit)  cnt++;
                num/=10;
            }
        }
        return cnt;
    }
};