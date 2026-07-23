class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> alt = {0};
        int count = 0;
        for (auto x : gain){
            count += x;
            alt.push_back(count);
        }
        int max = INT_MIN;
        for (auto x : alt){
            if( x > max) max = x;

        }
        return max;
    }
};