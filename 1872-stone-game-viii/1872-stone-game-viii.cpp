class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        // Prefix sums
        vector<int> prefix(n);
        prefix[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        // Base case: take all stones
        int dp = prefix[n - 1];

        // We can choose a prefix of length >= 2
        for (int i = n - 2; i >= 1; i--) {
            dp = max(dp, prefix[i] - dp);
        }

        return dp;
    }
};