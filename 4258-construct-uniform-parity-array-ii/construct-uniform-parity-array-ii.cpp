class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int min_odd = INT_MAX;
        int min_even = INT_MAX;
        int n = nums.size();
        for(int i = 0 ;i < n ; i++ ){
            if(nums[i]%2==0){
                if(nums[i]<min_even){
                    min_even = nums[i];
                }
            }else{
                if(nums[i]<min_odd){
                    min_odd = nums[i];
                }
            }
        }
        int count = 0 ;
        // check for even

        for(int i = 0 ; i< n ; i ++){
            if(nums[i]%2==0) {
                count++;
                continue;
            }else{
                if(nums[i]-min_odd>=1){
                    count++;
                    continue;
                }
            }
        }
        if(count==n) return true;
        count = 0;
        // check for odd
         for(int i = 0 ; i< n ; i ++){
            if(nums[i]%2!=0) {
                count++;
                continue;
            }else{
                if(nums[i]-min_odd>=1){
                    count++;
                    continue;
                }
            }
        }
        if(count==n) return true;

        return false;
    }
};