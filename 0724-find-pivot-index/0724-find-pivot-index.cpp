class Solution {
public:
    int pivotIndex(vector<int>& nums) {
     vector<int> prefix;
     int count = 0;
     for (auto x : nums){
        count += x;
        prefix.push_back(count);
     }
     int n = prefix.size();
     if(prefix[n - 1] - prefix[0] == 0) return 0;
     for (int i =1; i < n; i++){
        if(prefix[i-1] == prefix[n-1] - prefix[i])return i;
     }
    return -1;
    }
};