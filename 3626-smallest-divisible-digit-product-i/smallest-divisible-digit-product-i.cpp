class Solution {
public:
    int digitprd(int n){
        int prd = 1;
        while(n>0){
          int digit = n % 10;
          prd *= digit;
          n = n /10;
        }
        return prd;
    }
    int smallestNumber(int n, int t) {
        int ans = n;
        while((digitprd(ans)%t)!=0) ans++;
        return ans;
    }
};