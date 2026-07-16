class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxlen = 0;
        int right = 0 , left = 0;
        unordered_map<char,int> mp;

        while(right<n){
            char c = s[right];

            if(mp.find(c)!=mp.end()){
                left = max(left,mp[c] + 1);
            }
            maxlen = max(maxlen , right - left + 1);
            mp[c] = right;
            right++;
        }

        return maxlen;
    }
};