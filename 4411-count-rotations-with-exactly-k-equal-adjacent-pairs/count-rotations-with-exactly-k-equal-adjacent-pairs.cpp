class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        int score = 0;
        for(int i = 0 ; i < n ; i++){
            int d = n - i;
            string t = s;
            reverse(t.begin(), t.begin()+d);
            reverse(t.begin()+d, t.end());
            reverse(t.begin(), t.end());
            int count = 0;
            for(int i = 0 ; i< n ; i++){
                if(t[i]==t[i+1]){
                    count++;
                }
            }
            if(count==k){
                score++;
            }
        }

        return score;
    }
};