class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        // set<int> se(begin(arr),end(arr));
        // return se.size();
        sort(begin(arr),end(arr));

        int pre=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]==pre) continue;
            else{
                pre++;
            }
        }
        return pre;
    }
};