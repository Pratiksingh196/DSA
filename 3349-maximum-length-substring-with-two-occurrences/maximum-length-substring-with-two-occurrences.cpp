// class Solution {
// public:
//     int maximumLengthSubstring(string s) {
//         unordered_map<int,int> mp;
//         int n = s.size();
//         int i = 0;
//         int j = 0;
//         int result = 0;
//         while(j<n){
//             int ch = s[j] - 'a';
//             mp[ch]++;
//             while( mp[ch] > 2){
//                 int ch2 = s[i] - 'a';
//                 mp[ch]--;
//                 i++;
//             }
//            result = max(result, j-i + 1); 
//            j++;
//         }

//         return result;
//     }
// };

class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> mp;

        int i = 0;
        int result = 0;

        for (int j = 0; j < s.size(); j++) {
            mp[s[j]]++;

            while (mp[s[j]] > 2) {
                mp[s[i]]--;
                i++;
            }

            result = max(result, j - i + 1);
        }

        return result;
    }
};