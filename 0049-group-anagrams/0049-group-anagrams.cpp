class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for (string words : strs){
            string key = words;
            sort(key.begin(), key.end());
            mp[key].push_back(words);
        }

        for(auto& x: mp){
            ans.push_back(x.second);
        }




        return ans;
    }
};