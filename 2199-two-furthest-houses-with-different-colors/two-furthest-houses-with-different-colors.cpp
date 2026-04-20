class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int i = 0 ; 
        int j = colors.size()-1;
        int maxdis = 0;

        while(j>i){
          if(colors[i]!=colors[j]){
            maxdis= max(maxdis,abs(j-i));
            i++;
            j = colors.size()-1;
          }else{
            j--;
          }
        }

        return maxdis;
    }
};