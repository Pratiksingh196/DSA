class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        int res = INT_MAX;

        for(int i=0 ; i < n ;i++){
            for(int j= 0 ; j< m ; j++){
                int land = landStartTime[i]+landDuration[i];

                int final_time = max(land,waterStartTime[j]) + waterDuration[j];

                res = min(res , final_time);

                int water = waterStartTime[j]+waterDuration[j];

                int final_time1 = max(water,landStartTime[i]) + landDuration[i];

                res = min(res , final_time1);
            }
        }

        return res;
    }
};