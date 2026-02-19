class Solution {
public:
    int countBinarySubstrings(string s) {
        int curr = 1;
        int prev = 0;
        int res = 0;

        for(int i = 1; i<s.length();i++){
            if(s[i]==s[i-1]){
                curr += 1;
            }
            else{
                res += min(curr,prev);
                prev = curr;
                curr = 1;
            }
        }

        return res+min(prev,curr);
    }
};