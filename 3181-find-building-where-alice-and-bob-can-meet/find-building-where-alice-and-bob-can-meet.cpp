class Solution {
public:
    vector<int> segmentTree;
    int n;
    void buildSegmentTree(int i , int l , int r , vector<int>& heights){
        if(l==r){
            segmentTree[i] = l;
            return;
        }
        int mid = l +(r-l)/2;
        buildSegmentTree(2*i+1,l,mid,heights);
        buildSegmentTree(2*i+2,mid+1,r,heights);


        int leftIndex = segmentTree[2*i+1];
        int rightIndex = segmentTree[2*i+2];
        segmentTree[i] = (heights[leftIndex] >= heights[rightIndex]) ? leftIndex : rightIndex;
        
    }
    int querySegment(int start , int end , int i , int l , int r , vector<int>& heights){
        if(l>end || r < start){
            return -1;
        }
        if(l>=start && r <= end){
            return segmentTree[i];
        }
         int mid = l +(r-l)/2;

         int leftIndex = querySegment(start,end,2*i+1,l,mid,heights);
         int rightIndex = querySegment(start,end,2*i+2,mid+1,r,heights);

         if(leftIndex==-1){
            return rightIndex;
         }
         
         if(rightIndex==-1){
            return leftIndex;
         }

         return (heights[leftIndex]>=heights[rightIndex]) ? leftIndex : rightIndex;


    }
    int RMIQ(vector<int>& heights , int n , int a,int b){
        return querySegment(a,b,0,0,n-1,heights);
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        segmentTree.resize(4*n);
        buildSegmentTree(0,0,n-1,heights);

        vector<int> result;

        for(auto &query : queries){
            int min_idx = min(query[0],query[1]);
            int max_idx = max(query[0],query[1]);

            if(min_idx==max_idx){
                result.push_back(min_idx);
                continue;
            }else if(heights[max_idx]>heights[min_idx]){
                result.push_back(max_idx);
                continue;
            }

            int l = max_idx + 1;
            int r = n-1;
            int result_idx = INT_MAX;
            while(l<=r){
                int mid = l + (r-l)/2;
                int idx = RMIQ(heights,n,l,mid);
                if(heights[idx]>max(heights[min_idx],heights[max_idx])){
                    result_idx = min(result_idx,idx);
                    r = mid -1 ;
                }else{
                    l = mid + 1;
                }
            }
            if(result_idx==INT_MAX){
                result.push_back(-1);
            }else{
                result.push_back(result_idx);
            }
        }

        return result;
    }
};