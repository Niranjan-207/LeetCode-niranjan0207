class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i=left;i<=right;i++){
            string num=to_string(i);
            int j=0;
            for(;j<num.length();j++){
                int dig=num[j]-'0';
                if(dig==0 || i%dig!=0)   break;
                
            }
            if(j==num.length()) ans.push_back(i);
        }
        return ans;
    }
};