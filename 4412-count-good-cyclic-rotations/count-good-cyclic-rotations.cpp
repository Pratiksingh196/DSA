class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();

        long long total = 0;
        for (int x : nums) {
            total += x;
        }

        int half = n / 2;

        
        long long leftSum = 0;
        for (int i = 0; i < half; i++) {
            leftSum += nums[i];
        }

        int score = 0;

        for (int i = 0; i < n; i++) {

            long long rightSum = total - leftSum;

            if (leftSum < rightSum) {
                score++;
            }

        

            leftSum -= nums[i];
            leftSum += nums[(i + half) % n];
        }

        return score;
    }
};