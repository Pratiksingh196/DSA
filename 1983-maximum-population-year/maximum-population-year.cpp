class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> diff(2051,0);

        for(auto &log :logs){
            int birth = log[0];
            int death = log[1];

            diff[birth] += 1;
            diff[death] -= 1;
        }

        int curpop = 0 ;
        int maxpop = 0;
        int minyear = 2050;

        for(int i = 1950 ; i < 2051 ; i++){
            curpop += diff[i];
            if(curpop > maxpop){
                maxpop = curpop;
                minyear = i;
            }
        }

        return minyear;
    }
};