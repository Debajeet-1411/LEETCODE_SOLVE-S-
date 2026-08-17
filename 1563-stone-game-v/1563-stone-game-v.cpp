class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        // Prefix sums
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        auto sum = [&](int l, int r) -> long long {
            return prefix[r + 1] - prefix[l];
        };

        // dp[l][r] = maximum score Alice can get from [l, r]
        vector<vector<long long>> dp(n, vector<long long>(n, 0));

        // Process intervals from short to long
        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len <= n; l++) {
                int r = l + len - 1;

                for (int k = l; k < r; k++) {
                    long long left = sum(l, k);
                    long long right = sum(k + 1, r);

                    if (left < right) {
                        dp[l][r] = max(
                            dp[l][r],
                            left + dp[l][k]
                        );
                    }
                    else if (left > right) {
                        dp[l][r] = max(
                            dp[l][r],
                            right + dp[k + 1][r]
                        );
                    }
                    else {
                        // Equal: Alice chooses which side to discard
                        dp[l][r] = max({
                            dp[l][r],
                            left + dp[l][k],
                            right + dp[k + 1][r]
                        });
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};