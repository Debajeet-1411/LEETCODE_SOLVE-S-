class Solution {
public:
    int reverse(int x) {
        int num = x;
        long rev_num = 0;
        while(num != 0){
            int last_dig = num % 10;
            rev_num = rev_num * 10 + last_dig;
            num = num/10;
        }

        if (rev_num > INT_MAX || rev_num < INT_MIN) return 0;
        // if (x < 0){
        //     rev_num = -1 * rev_num;
        // }
        return rev_num;
        
    }
};