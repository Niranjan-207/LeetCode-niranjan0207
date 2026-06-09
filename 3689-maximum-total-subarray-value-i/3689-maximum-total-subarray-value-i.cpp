class Solution {
public:
    #define ll long long
    long long maxTotalValue(vector<int>& nums, int k) {
        ll mi=*min_element(begin(nums),end(nums));
        ll ma=*max_element(begin(nums),end(nums));
        return (k*(ma-mi));
    }
};