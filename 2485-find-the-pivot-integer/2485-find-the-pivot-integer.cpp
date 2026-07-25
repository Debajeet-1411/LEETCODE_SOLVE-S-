class Solution {
public:
    int pivotInteger(int n) {
        int count = 0;
        vector<int> prefix;
        vector<int> nums;
        if(n == 1)return 1;
        for (int i =1; i <=n; i++){
            count += i;
            prefix.push_back(count);
            nums.push_back(i);
        }
        if(prefix[prefix.size() -1] == 0) return 0;
        //now i got the prefix sum 
        for (int i = 1 ; i< prefix.size(); i++){
            if(prefix[i] == prefix[prefix.size() -1] - prefix[i -1]){
                return nums[i];
            }
        }
        return -1;
    }
};