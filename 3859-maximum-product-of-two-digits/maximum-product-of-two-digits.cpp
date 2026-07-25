class Solution {
public:
    int maxProduct(int n) {
        vector<int> ans;
        while(n>0){
            int digit = n%10;
            ans.push_back(digit);
            n = n / 10;
        }

        sort(ans.begin() , ans.end());
        reverse(ans.begin() , ans.end());

        return ans[0]*ans[1];

    }
};