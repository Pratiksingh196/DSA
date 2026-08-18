class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {

        vector<pair<int,int>> pg;

        int n = plantTime.size();

        for(int i = 0; i < n; i++) {
            pg.push_back({plantTime[i], growTime[i]});
        }

        sort(pg.begin(), pg.end(),
            [](const auto& a, const auto& b) {

                return a.second > b.second;
            });

        int curr_time = 0;
        int total_time = 0;

        for(auto &[pt, gt] : pg) {

            curr_time += pt;

            total_time = max(total_time, curr_time + gt);
        }

        return total_time;
    }
};