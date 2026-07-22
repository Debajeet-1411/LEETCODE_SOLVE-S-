class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;
        for(int i =0; i < nums1.size(); i++){
            freq[nums1[i]]++;
        }
    // created the hash map now need to checkk the existance
    vector<int> ans;
    for (auto x : nums2){
        if(freq[x] > 0){
            ans.push_back(x);
            freq[x] -= 1;
        }
    }
    return ans;

    }
};