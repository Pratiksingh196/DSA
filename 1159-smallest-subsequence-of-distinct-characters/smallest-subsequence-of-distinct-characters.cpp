class Solution {
public:
    string smallestSubsequence(string s) {
        vector<bool> token(26,false);
        vector<int> idx(26);
        int n = s.size();
        string result;

        for(int i = 0 ; i < n ; i++){
            char ch = s[i];

            idx[ch-'a'] = i;
        }

        for(int i = 0 ; i < n ; i ++){
           char ch = s[i];
           int index = s[i] - 'a';
           if(token[index] == true){
              continue;
           }

           while( result.size() > 0  && result.back() > ch && idx[result.back() - 'a'] > i ){
               token[result.back() - 'a'] = false;
               result.pop_back();
           }

           result.push_back(ch);
           token[index] = true;
        }

        return result;
    }
};