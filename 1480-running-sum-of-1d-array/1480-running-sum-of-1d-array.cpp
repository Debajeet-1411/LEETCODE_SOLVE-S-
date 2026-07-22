class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> sums;
        int count = 0;
        for(auto x : nums){
            count += x;
            sums.push_back(count);
        }
        return sums;
    }
};