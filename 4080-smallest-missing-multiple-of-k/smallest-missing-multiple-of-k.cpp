class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
        }
        bool value = true;
        int ans = 0;
        int i =1;
        while(value){
            if(mp.find(k*i)!=mp.end()){
                i++;
            }else{
                ans = k*i;
                break;
            }
            
        }
        return ans;
    }
};