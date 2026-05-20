class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        set<int> s1,s2,com;
        s1.insert(begin(nums1),end(nums1));

        for(int num:nums2){
            s2.insert(num);
            if(s1.count(num))   com.insert(num);
        }
        int comSize=com.size();
        int t1=min((int)s1.size()-comSize,n/2);
        int t2=min((int)s2.size()-comSize,n/2);
        return min(n,t1+t2+comSize);

    }
};