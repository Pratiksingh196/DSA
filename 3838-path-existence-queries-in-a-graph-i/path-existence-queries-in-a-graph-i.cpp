class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> gp(n,0);

        int cu = 0 ;
        for(int i = 1; i < n ; i++){
            if(nums[i] - nums[i-1] > maxDiff){
                cu++;
            }
            gp[i]  = cu;
        }
        vector<bool> ans;

        for(int i = 0 ; i < queries.size() ; i++){
            if(gp[queries[i][0]]==gp[queries[i][1]]){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            };
        }

        return ans;
    }
};