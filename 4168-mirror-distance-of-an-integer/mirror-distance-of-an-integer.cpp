class Solution {
public:
    int mirrorDistance(int n) {
        int ono = n;
        int reverse = 0;
        while(n>0){
            reverse = reverse*10;
            reverse = reverse + n%10;
            n = n /10;
        }

        return abs(ono-reverse);
    }
};