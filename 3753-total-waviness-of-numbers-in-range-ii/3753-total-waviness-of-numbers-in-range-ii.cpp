class Solution {
public:
    using ll = long long;

    string s;
    int n;

    ll dpTotalNumbers[20][11][11];
    ll dpTotalWaviness[20][11][11];

    pair<ll, ll> solve(int cur, int pre, int prePre, bool tight, bool lz) {

        if (cur == n)
            return {1, 0};

        if (!tight && !lz) {
            int p = pre + 1;
            int pp = prePre + 1;

            if (dpTotalNumbers[cur][p][pp] != -1) {
                return {
                    dpTotalNumbers[cur][p][pp],
                    dpTotalWaviness[cur][p][pp]
                };
            }
        }

        ll totalNumbers = 0;
        ll totalWaveScore = 0;

        int limit = tight ? (s[cur] - '0') : 9;

        for (int dig = 0; dig <= limit; dig++) {

            bool nlz = lz && (dig == 0);

            int newPrePre;
            int newPre;

            if (nlz) {
                newPre = -1;
                newPrePre = -1;
            } else if (lz) {
                newPre = dig;
                newPrePre = -1;
            } else {
                newPrePre = pre;
                newPre = dig;
            }

            auto [remainTotalNumbers, remainTotalWaveScore] =
                solve(
                    cur + 1,
                    newPre,
                    newPrePre,
                    tight && (dig == limit),
                    nlz
                );

            totalWaveScore += remainTotalWaveScore;

            if (!nlz && pre >= 0 && prePre >= 0) {
                bool isPeak = (prePre < pre && pre > dig);
                bool isValley = (prePre > pre && pre < dig);

                if (isPeak || isValley)
                    totalWaveScore += remainTotalNumbers;
            }

            totalNumbers += remainTotalNumbers;
        }

        if (!tight && !lz) {
            int p = pre + 1;
            int pp = prePre + 1;

            dpTotalNumbers[cur][p][pp] = totalNumbers;
            dpTotalWaviness[cur][p][pp] = totalWaveScore;
        }

        return {totalNumbers, totalWaveScore};
    }

    ll fun(long long num) {

        if (num < 100)
            return 0;

        memset(dpTotalNumbers, -1, sizeof(dpTotalNumbers));
        memset(dpTotalWaviness, -1, sizeof(dpTotalWaviness));

        s = to_string(num);
        n = (int)s.size();

        auto [totalNumbers, totalWaveScore] =
            solve(0, -1, -1, true, true);

        return totalWaveScore;
    }

    long long totalWaviness(long long num1, long long num2) {
        return fun(num2) - fun(num1 - 1);
    }
};