class Solution {
public:
    int minPartitions(string n) {
        sort(n.begin(), n.end());
        int m = n.length();
        return (n[m-1] - '0');
    }
};