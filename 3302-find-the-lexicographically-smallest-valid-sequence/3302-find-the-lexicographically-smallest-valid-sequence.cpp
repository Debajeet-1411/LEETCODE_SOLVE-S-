class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        // rightStart[j] = the largest possible first index of an
        // embedding of word2[j..m-1] in word1.
        // -1 means the suffix cannot be embedded.
        vector<int> rightStart(m + 1, -1);
        rightStart[m] = n;

        int limit = n;
        for (int j = m - 1; j >= 0; --j) {
            if (limit < 0) continue;

            int p = limit - 1;
            while (p >= 0 && word1[p] != word2[j])
                --p;

            if (p < 0) {
                limit = -1;
            } else {
                rightStart[j] = p;
                limit = p;
            }
        }

        vector<int> ans;
        int prev = -1;
        bool changed = false;

        for (int j = 0; j < m; ++j) {
            bool found = false;

            for (int i = prev + 1; i < n; ++i) {
                // Exact match is always safe and gives the earliest
                // possible index if it is encountered first.
                if (word1[i] == word2[j]) {
                    ans.push_back(i);
                    prev = i;
                    found = true;
                    break;
                }

                // Use our one allowed mismatch if the remaining suffix
                // can be matched exactly after this index.
                if (!changed && rightStart[j + 1] > i) {
                    ans.push_back(i);
                    prev = i;
                    changed = true;
                    found = true;
                    break;
                }
            }

            if (!found)
                return {};
        }

        return ans;
    }
};