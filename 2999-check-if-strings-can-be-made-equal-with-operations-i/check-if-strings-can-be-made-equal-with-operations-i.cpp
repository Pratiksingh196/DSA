class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        // if(s1[0]==s2[2] && s1[1]==s2[3] && s2[0]==s1[2] && s2[1]==s1[3]) {
        //     return true;
        // }else if(s1[0]==s2[0] && s2[2]==s1[2] && s1[1]==s2[3] && s2[1]==s1[3] ){
        //     return true;
        // }else if(s1[1]==s2[1] && s2[3]==s1[3] && s1[0]==s2[2]  && s2[0]==s1[2]){
        //     return true;
        // }else if(s1[0]==s2[0] && s1[1]==s2[1] && s1[2]==s2[2] && s1[3]==s2[3]){
        //     return true;
        // }else{
        //     return false;
        // }
            
        for(int i = 0 ; i <2 ; i++){
            if(s1[i]!=s2[i]){
                swap(s1[i],s1[i+2]);
            }
        }
        if(s1==s2){
            return true;
        }else{
            return false;
        }
    }
};