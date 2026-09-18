class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for(auto x : strs){
            string word = x;
            sort(word.begin(), word.end());
            mp[word].push_back(x);
        }

        for(auto i : mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};