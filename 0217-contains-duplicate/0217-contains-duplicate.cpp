class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> se;
        for(int num:nums){
            if(se.count(num))   return true;
            else    se.insert(num);
        }
        return false;
    }
};