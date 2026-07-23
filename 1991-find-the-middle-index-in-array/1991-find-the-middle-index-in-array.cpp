class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int count =0;
        vector<int> prefix;
        for (auto x : nums){
            count += x;
            prefix.push_back(count);
        }
        int n = prefix.size();
        if (prefix[n-1] - prefix[0] == 0) return 0;
        
        for (int i =1; i<n;i++){
            if(prefix[i-1] == prefix[n-1] - prefix[i]) return i;
        }
        if(prefix[n-2] == 0) return n-1;
    return -1;}
};