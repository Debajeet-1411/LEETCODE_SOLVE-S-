class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pr = 1;
        unordered_map<int,int> zeros;
        
        for (auto x : nums){
           
            if (x != 0){
            pr *= x;
            }
            else{
                zeros[x]++;
            }
        }

    //i have the set to find weteher 0 is there in the vector
    //i have the multiplicationn vector too
    vector<int> ans;
    if(zeros[0]>1){
                ans.resize(nums.size(),0);
                return ans;
            }
    
    else if(zeros[0] < 1){
        for (auto x: nums){
            int n = pr / x;
            ans.push_back(n);
        }
    }
    else if (zeros[0] == 1){
        for (auto x : nums){
            if (x != 0){
                ans.push_back(0);
            }
            else{
               
                ans.push_back(pr);
            }
        }
    }      


        return ans;
    }
};