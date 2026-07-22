class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen_nums;
        for(auto x : nums){
            if(seen_nums.find(x) != seen_nums.end()){
                return (1 == 1);
            }
            seen_nums.insert(x);
        }
    return (1 == 2);
    }
};