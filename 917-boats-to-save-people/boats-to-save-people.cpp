class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin() , people.end());
        int cnt = 0;
        int l = limit;
        int i=0;
        int j = people.size() - 1;
        while(i<=j){
            int p = people[j];
            int req = l-p;
            if(req==0|| req < people[i]){
              cnt++;
              j--;
              continue;
            }
            i++;
            j--;
            cnt++; 
        }

        return cnt;

    }
};