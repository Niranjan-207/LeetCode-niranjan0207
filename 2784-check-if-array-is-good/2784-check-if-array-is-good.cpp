class Solution {
public:
    bool isGood(vector<int>& nums) {
        bitset<201> bs;
        int n=nums.size();
        int ncnt=0;
        int cnt=0;
        for(int num:nums){
            if(num<(n-1)){
                if(bs[num]) return false;
                else{
                    bs[num]=1;
                    cnt++;
                }
            }else if(num==(n-1)){
                ncnt++;
            }else{
                return false;
            }
        }
        return (ncnt==2 && (cnt+ncnt)==n);
    }
};