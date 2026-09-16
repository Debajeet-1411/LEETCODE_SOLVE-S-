class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long long org_num = x;
        long long rev_num = 0;
        while(x != 0){
            int last_dig = x % 10;
            rev_num = rev_num * 10 + last_dig;
            x = x/10;
        }
        return (org_num == rev_num);
    }
};