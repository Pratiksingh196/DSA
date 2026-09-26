class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;

        for(auto& l: knowledge){
            mp[l[0]] = l[1];
        }

        string res = "";
        string key = "";

        bool flag = false;

        for(char ch : s){
            if(ch=='('){
                flag = true;
            }
            else if(ch==')'){
                if(mp.find(key) != mp.end()){
                    res += mp[key];
                }
                else{
                    res += "?";
                }
                flag = false;
                key = "";
            }
            else if(flag){
                key += ch;
            }else{
                res +=ch;
            }
        }

        return res;
    }
};