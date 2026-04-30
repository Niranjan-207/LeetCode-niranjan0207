class Solution {
public:
    int bsl(vector<int>& arr,int k){
        int l=0;
        int r=arr.size()-1;
        int idx=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]==k){
                idx=mid;
                r=mid-1;
            }else if(k<arr[mid]){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return idx;
    }

    int bsr(vector<int>& arr,int k){
        int l=0;
        int r=arr.size()-1;
        int idx=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]==k){
                idx=mid;
                l=mid+1;
            }else if(k<arr[mid]){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return idx;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(bsl(nums,target));
        ans.push_back(bsr(nums,target));
        return ans;
    }
};