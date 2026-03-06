class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length();
        for(int i = 1 ; i < n-1; i++){
            string sub = s.substr(i, 2);
            if(sub == "01"){
                return false;
            }
        }

        return true;
    }
};