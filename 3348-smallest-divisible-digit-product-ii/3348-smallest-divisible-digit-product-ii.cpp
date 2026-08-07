
class Solution {
public:
    string smallestNumber(string num, long long t) {
        // Step 1: Factorize t into prime factors 2, 3, 5, 7
        long long temp = t;
        vector<long long> req(4, 0); // counts for 2, 3, 5, 7
        vector<int> primes = {2, 3, 5, 7};
        
        for (int i = 0; i < 4; ++i) {
            while (temp % primes[i] == 0) {
                req[i]++;
                temp /= primes[i];
            }
        }
        
        // If t has prime factors other than 2, 3, 5, 7, no zero-free digit product can be divisible by t
        if (temp > 1) {
            return "-1";
        }

        // Helper to find the minimal multiset of digits needed to satisfy remaining factor requirements
        auto get_min_digits = [](long long a, long long b, long long c, long long d) {
            a = max(0LL, a);
            b = max(0LL, b);
            c = max(0LL, c);
            d = max(0LL, d);

            vector<int> res;
            for (int i = 0; i < c; ++i) res.push_back(5);
            for (int i = 0; i < d; ++i) res.push_back(7);

            long long n8 = a / 3;
            long long ra = a % 3;
            long long n9 = b / 2;
            long long rb = b % 2;

            for (int i = 0; i < n8; ++i) res.push_back(8);
            for (int i = 0; i < n9; ++i) res.push_back(9);

            if (ra == 1 && rb == 1) {
                res.push_back(6);
            } else if (ra == 2 && rb == 1) {
                res.push_back(2);
                res.push_back(6);
            } else if (ra == 1 && rb == 0) {
                res.push_back(2);
            } else if (ra == 2 && rb == 0) {
                res.push_back(4);
            } else if (ra == 0 && rb == 1) {
                res.push_back(3);
            }

            sort(res.begin(), res.end());
            return res;
        };

        // Factors contributed by each digit from 1 to 9
        vector<vector<int>> digit_factors = {
            {0, 0, 0, 0}, // 0 (unused)
            {0, 0, 0, 0}, // 1
            {1, 0, 0, 0}, // 2
            {0, 1, 0, 0}, // 3
            {2, 0, 0, 0}, // 4
            {0, 0, 1, 0}, // 5
            {1, 1, 0, 0}, // 6
            {0, 0, 0, 1}, // 7
            {3, 0, 0, 0}, // 8
            {0, 2, 0, 0}  // 9
        };

        int n = num.length();
        int first_zero = num.find('0');
        if (first_zero == -1) {
            first_zero = n;
        }

        // Precompute prefix factor counts
        vector<vector<long long>> pref_factors(n + 1, vector<long long>(4, 0));
        for (int i = 0; i < min(n, first_zero); ++i) {
            int d = num[i] - '0';
            for (int j = 0; j < 4; ++j) {
                pref_factors[i + 1][j] = pref_factors[i][j] + digit_factors[d][j];
            }
        }

        // Check if num itself is valid
        if (first_zero == n) {
            bool valid = true;
            for (int j = 0; j < 4; ++j) {
                if (pref_factors[n][j] < req[j]) {
                    valid = false;
                    break;
                }
            }
            if (valid) return num;
        }

        // Try matching prefix of length i from right to left
        for (int i = min(n - 1, first_zero); i >= 0; --i) {
            int start_d = (i < first_zero) ? (num[i] - '0' + 1) : 1;
            
            for (int d = start_d; d <= 9; ++d) {
                long long rem_a = req[0] - pref_factors[i][0] - digit_factors[d][0];
                long long rem_b = req[1] - pref_factors[i][1] - digit_factors[d][1];
                long long rem_c = req[2] - pref_factors[i][2] - digit_factors[d][2];
                long long rem_d = req[3] - pref_factors[i][3] - digit_factors[d][3];

                vector<int> min_digits = get_min_digits(rem_a, rem_b, rem_c, rem_d);
                int rem_len = n - 1 - i;

                if (min_digits.size() <= rem_len) {
                    string prefix = num.substr(0, i) + to_string(d);
                    string suffix = string(rem_len - min_digits.size(), '1');
                    for (int digit : min_digits) {
                        suffix += to_string(digit);
                    }
                    return prefix + suffix;
                }
            }
        }

        // If no solution of length n exists, create the smallest number of length > n
        vector<int> min_digits = get_min_digits(req[0], req[1], req[2], req[3]);
        int target_len = max(n + 1, (int)min_digits.size());
        string res = string(target_len - min_digits.size(), '1');
        for (int digit : min_digits) {
            res += to_string(digit);
        }
        return res;
    }
};