class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> se;
        for(int num:arr1){
            while(num){
                se.insert(num);
                num/=10;
            }
        }

        int ans=0;
        for(int num:arr2){
            while(num){
                if(se.count(num) && num>ans)    ans=num;
                num/=10;
            }
        }
        return ans==0?0:(int)to_string(ans).size();
    }
};