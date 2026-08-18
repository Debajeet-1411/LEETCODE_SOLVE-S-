class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos;

        for (int i = 0; i < n; i++)
            pos[nums[i]].push_back(i);

        int ans = -1;
        int totalWindows = n - k + 1;

        for (auto& [x, v] : pos) {
            int windows = totalWindows;

            int gap = v[0];
            windows -= max(0, gap - k + 1);

            for (int i = 1; i < v.size(); i++) {
                gap = v[i] - v[i - 1] - 1;
                windows -= max(0, gap - k + 1);
            }

            gap = n - 1 - v.back();
            windows -= max(0, gap - k + 1);

            if (windows == 1)
                ans = max(ans, x);
        }

        return ans;
    }
};