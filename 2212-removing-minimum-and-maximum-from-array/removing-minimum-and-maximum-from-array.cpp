class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        
        int minele = INT_MAX, maxele = INT_MIN;
        int minidx = -1, maxidx = -1;
        
        // Use independent if statements to evaluate every element for both min and max
        for(int i = 0 ; i < n ; i++){
            if(nums[i] > maxele){
                maxele = nums[i];
                maxidx = i;
            }
            if(nums[i] < minele){
                minele = nums[i];
                minidx = i;
            }
        }
        
        // Calculate the three possible deletion strategies
        int both_from_front = max(minidx, maxidx) + 1;
        int both_from_back = n - min(minidx, maxidx);
        int opposite_ends = min(minidx, maxidx) + 1 + n - max(minidx, maxidx);
        
        // Return the most optimal strategy
        return min({both_from_front, both_from_back, opposite_ends});
    }
};