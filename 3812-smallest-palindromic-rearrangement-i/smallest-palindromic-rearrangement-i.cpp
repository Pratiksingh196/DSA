class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();

        string first = s.substr(0, n / 2);
        sort(first.begin(), first.end());

        string rev = first;
        reverse(rev.begin(), rev.end());

        if (n % 2 == 0) {
            return first + rev;
        } else {
            return first + s[n / 2] + rev;
        }
    }
};