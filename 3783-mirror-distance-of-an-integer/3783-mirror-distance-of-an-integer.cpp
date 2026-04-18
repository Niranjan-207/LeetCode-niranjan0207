class Solution {
public:
    int mirrorDistance(int n) {
        string s=to_string(n);
        reverse(begin(s),end(s));
        int num=stoi(s);

        return abs(num-n);
    }
};