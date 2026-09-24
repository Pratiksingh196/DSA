class Solution {
public:
    int solve(int i){
        int sum = 0;
           while(i>0){
            int digit = i%10;
            sum+=digit;
            i = i/10;
           }

           return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0 ; i < n ; i++){
            int ds = solve(nums[i]);

            if(ds==i){
                return i;
            }
        }

        return -1;
    }
};