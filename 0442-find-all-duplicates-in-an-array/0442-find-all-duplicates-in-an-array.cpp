class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     int num=nums[i]-1;
        //     if(num<1)   continue;
        //     int idx=i;
        //     while(num != idx){
        //         int nnum=nums[idx]-1;
        //         if(nums[num]>0){
        //             nums[num]=-1;
        //         }else{
        //             nums[num]-=1;
        //         }
        //         //nums[num]-=1;
        //         num=nnum;
        //         idx=num;
        //     }
        // }
        
        // for(int num:nums)   cout<<num<<" ";
        // vector<int> ans;
        // for(int i=0;i<n;i++){
        //     if(nums[i]==-2)  ans.push_back(i+1);
        // }
        // return ans;
        int i = 0, n = nums.size();

        while (i < n) {
            int correct = nums[i] - 1;

            if (nums[i] != nums[correct])
                swap(nums[i], nums[correct]);
            else
                i++;
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                ans.push_back(nums[i]);
        }

        return ans;
    }
};