class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<int> seen;
        int count =0;
        for(auto x : jewels){
            seen.insert(x);
        }
        for(auto x : stones){
            if (seen.find(x) != seen.end()){
                count++;
            }
        }
    return count;
    }
};