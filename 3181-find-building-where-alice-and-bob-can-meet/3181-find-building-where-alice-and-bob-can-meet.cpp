

class Solution {
public:

    struct SegmentTree{
        vector<int>seg;
        int n;

        SegmentTree(vector<int>&height, int n){
            this->n = n;
            seg.assign(4*n,0);
            buildTree(0,0,n-1,height);
        }

        void buildTree(int idx , int low ,int high , vector<int>&arr){
            if(low == high){
                seg[idx] = low;
                return ;
            }
            int mid = low + (high - low)/2;
            buildTree(2*idx+1,low,mid,arr);
            buildTree(2*idx+2,mid+1,high,arr);

            int leftIndex = seg[2*idx+1];
            int rightIndex = seg[2*idx+2];

            if(arr[leftIndex]>=arr[rightIndex]){
                seg[idx] = leftIndex;
            }
            else{
                seg[idx] = rightIndex;
            }

        }


        int query(int idx , int low , int high , int l , int r , vector<int>&arr){
            if(low > r || high < l)return -1;
            if(low >= l && high <= r){
                return seg[idx];
            }
            int mid = low + (high - low)/2;
            int left = query(2*idx+1,low,mid,l,r,arr);
            int right = query(2*idx+2,mid+1,high,l,r,arr);

            if(left == -1)return right;
            if(right == -1)return left;

            if(arr[left] >= arr[right]){
                return left;
            }
            return right;

        }

        int query(int start , int end , vector<int>&heights,int limit){
            int low = start;
            int high = end;
            int ans = -1;
            while(low<=high){
                int mid = low + (high - low)/2;
                int idx = query(0,0,n-1,low,mid,heights);
                if(idx!=-1 && heights[idx]> limit){
                    ans = idx;
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            return ans;;
        }



    };


    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries){ 
        int n = heights.size();
        SegmentTree sg(heights,n);
        vector<int>ans;
        for(auto & it: queries){
             int a = it[0], b = it[1];
            if (a > b) swap(a, b);  

            if (a == b) {
                ans.push_back(a);
                continue;
            }

            if (heights[b] > heights[a]) {
                ans.push_back(b);
                continue;
            }

            if (b == n - 1) { 
                ans.push_back(-1);
                continue;
            }

            int limit = max(heights[a], heights[b]);
            int res = sg.query(b+1,n-1,heights,limit);
            ans.push_back(res);

        }

        return ans;
    }
};