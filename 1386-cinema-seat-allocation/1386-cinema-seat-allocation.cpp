class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;

        for (auto &seat : reservedSeats) {
            int r = seat[0], s = seat[1];
            rows[r] |= (1 << s);
        }

        int ans = (n - rows.size()) * 2;

        for (auto &[r, mask] : rows) {
            bool left = !(mask & ((1 << 2) | (1 << 3) | (1 << 4) | (1 << 5)));
            bool right = !(mask & ((1 << 6) | (1 << 7) | (1 << 8) | (1 << 9)));

            if (left && right)
                ans += 2;
            else if (left || right)
                ans += 1;
            else if (!(mask & ((1 << 4) | (1 << 5) | (1 << 6) | (1 << 7))))
                ans += 1;
        }

        return ans;
    }
};