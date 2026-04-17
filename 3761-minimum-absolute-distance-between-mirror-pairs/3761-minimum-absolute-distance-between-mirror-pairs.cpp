class Solution {
public:
    int reverse(int num){
        int n=0;
        while(num>0){
            int dig=num%10;
            n=(n*10)+dig;
            num/=10;
        }
        return n;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mp;
        int dif=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int cur=nums[i];
            if(mp.count(cur)){
                int j=mp[cur];
                dif=min(dif,i-j);
            }
            int rev=reverse(nums[i]);
            mp[rev]=i;
        }
        if(dif==INT_MAX)    return -1;
        return dif;
    }
};