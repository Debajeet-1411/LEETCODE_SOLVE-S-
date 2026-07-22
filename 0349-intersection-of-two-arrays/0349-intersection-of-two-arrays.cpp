class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> seen1;
        vector<int> ans;
        for (auto x : nums1){
            seen1.insert(x);
        }
        for(auto x : nums2){
            if (seen1.find(x) != seen1.end()){
                auto it = find(ans.begin(), ans.end(), x);
                if(it == ans.end()) ans.push_back(x);
            }
        }
    return ans;
    }
};