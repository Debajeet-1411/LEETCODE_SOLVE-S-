class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
     if (magazine.size()< ransomNote.size()) return false;
    //  unordered_map<char, int> freq1;
    //  for(auto x : ransomNote) freq1[x]++;   
     unordered_map<char, int> freq2;
     for(auto x : magazine) freq2[x]++; 

     for (auto x : ransomNote){
        freq2[x]--;
        if(freq2[x] <0) return false;
     }
    return true;
    }
};