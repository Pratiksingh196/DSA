class Solution {
public:
    // int candy(vector<int>& r) {
    //     // int n = r.size();
    //     // int sum = 1 ; 
    //     // int i = 1;
    //     // while(i<n){
    //     //     if(r[i]==r[i-1]){
    //     //         sum += 1 ;
    //     //         i++;
    //     //         continue;
    //     //     }
    //     //     int peak = 1;
    //     //     while(i<n && r[i]>r[i-1]){
    //     //         peak +=1;
    //     //         sum += peak;
    //     //         i++;
    //     //     }
    //     //     int down = 1;
    //     //     while(i<n && r[i]<r[i-1]){
    //     //         down += 1;
    //     //         sum += down;
    //     //         i++;
    //     //     }
    //     //     if(down>peak){
    //     //         sum += (down-peak);
    //     //     }
    //     // }

    //     // return sum;
        

        
    // }
    int candy(vector<int>& r) {
    int n = r.size();
    vector<int> candies(n,1);

    for(int i=1;i<n;i++){
        if(r[i] > r[i-1])
            candies[i] = candies[i-1] + 1;
    }

    for(int i=n-2;i>=0;i--){
        if(r[i] > r[i+1])
            candies[i] = max(candies[i], candies[i+1] + 1);
    }

    int sum = 0;
    for(int c : candies) sum += c;

    return sum;
}
};