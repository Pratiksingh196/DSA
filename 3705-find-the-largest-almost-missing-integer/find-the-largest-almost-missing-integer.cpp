class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1;
        int j = k-1;
        int t = 0;
        unordered_map<int,int> mp;
        if(k == nums.size()){
            for(int i= 0 ; i < nums.size() ; i++){
                ans = max(ans,nums[i]);
            }
            return ans;
        }

        while(j<n){
            for(int i = t; i <=j ; i++){
                mp[nums[i]]++;
            }
            j++;
            t++;
        }
        int minfreq = INT_MAX;
        for(auto &it:mp){
           if(it.second<2){
            minfreq = it.second;
            if(it.first > ans){
            ans  = it.first;
           }
           }
        }

        return ans;
    }
};