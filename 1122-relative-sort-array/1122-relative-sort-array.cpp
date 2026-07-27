class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> sorted;
        unordered_map<int,int> freq;
        for(auto x : arr1){
            freq[x]++;
        }
        unordered_set<int> m2;
        for(auto x : arr2){
            m2.insert(x);
            auto it = freq.find(x);
            if(it != freq.end()){
                for(int i = 0; i < it->second; i++){
                    sorted.push_back(x);
                }
            }
        }
        int n = sorted.size();
        for(auto x : arr1){
            if (m2.find(x) == m2.end()){
                sorted.push_back(x);
            }
        }
        sort(sorted.begin() + n , sorted.end());
       return sorted; 
    }
};