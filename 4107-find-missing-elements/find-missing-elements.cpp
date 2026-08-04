class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        set<int> s;
        s.insert(nums.begin(), nums.end());
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int minele = nums[0];
        int maxele = nums[n-1];
    
        vector<int> ans;
        for(int i = minele ; i <= maxele ; i++){
            if(s.find(i)!=s.end()){
                continue;
            }else{
                ans.push_back(i);
            }
        }
    return ans;
    }
};