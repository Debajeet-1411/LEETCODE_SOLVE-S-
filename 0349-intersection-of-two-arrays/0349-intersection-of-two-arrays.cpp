class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> seen1;
        unordered_set<int> ans;
        for (auto x : nums1){
            seen1.insert(x);
        }
        for(auto x : nums2){
            if (seen1.find(x) != seen1.end()){
                if(ans.find(x) == ans.end())ans.insert(x);
            }
        }
    return vector<int>(ans.begin(), ans.end());
    }
};