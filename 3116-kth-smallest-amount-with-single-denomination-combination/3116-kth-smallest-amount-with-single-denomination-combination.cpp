class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        
        // Remove redundant coins: if a coin is a multiple of another,
        // its multiples are already covered.
        sort(coins.begin(), coins.end());
        vector<int> c;
        
        for (int x : coins) {
            bool redundant = false;
            for (int y : c) {
                if (x % y == 0) {
                    redundant = true;
                    break;
                }
            }
            if (!redundant) c.push_back(x);
        }
        
        n = c.size();
        
        auto gcd = [](long long a, long long b) {
            while (b) {
                long long t = a % b;
                a = b;
                b = t;
            }
            return a;
        };
        
        auto lcm = [&](long long a, long long b) {
            return a / gcd(a, b) * b;
        };
        
        // Count distinct amounts <= x using inclusion-exclusion.
        auto count = [&](long long x) {
            long long total = 0;
            
            for (int mask = 1; mask < (1 << n); mask++) {
                long long L = 1;
                int bits = 0;
                bool overflow = false;
                
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;
                        L = lcm(L, (long long)c[i]);
                        if (L > x) {
                            overflow = true;
                            break;
                        }
                    }
                }
                
                if (overflow) continue;
                
                long long ways = x / L;
                
                if (bits & 1)
                    total += ways;
                else
                    total -= ways;
            }
            
            return total;
        };
        
        long long lo = 1;
        long long hi = 1LL * (*min_element(c.begin(), c.end())) * k;
        
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            
            if (count(mid) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }
        
        return lo;
    }
};