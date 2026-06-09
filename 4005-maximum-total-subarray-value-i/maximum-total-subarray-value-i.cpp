class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        long long minEle = nums[0];
        long long maxEle = nums[n-1];

        return (maxEle-minEle)*k;
    }
};