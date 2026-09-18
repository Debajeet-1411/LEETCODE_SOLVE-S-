class Solution {
public:
    int addDigits(int num) {
        
        while(num >= 10){
            int last_dig = num % 10;
            num = num/10 + last_dig;
        }
        return num;
    }
};