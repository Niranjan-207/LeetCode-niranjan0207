class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> dp(2 * limit + 2, 0);
        for (int i = 0; i < n / 2; i++) {
            int mini = min(nums[i], nums[n - 1 - i]);
            int maxi = max(nums[i], nums[n - 1 - i]);
            dp[2] += 2;
            dp[mini + 1] -= 1;
            dp[mini + maxi] -= 1;
            dp[mini + maxi + 1] += 1;
            dp[maxi + limit + 1] += 1;
        }
        int res = n;
        int moves = 0;
        for (int c = 2; c <= 2 * limit; c++) {
            moves += dp[c];
            res = min(res, moves);
        }

        return res;
    }
};