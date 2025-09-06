class Solution {
public:
    double findMedianSortedArrays(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size();
        int m = arr2.size();
        if(n>m)return findMedianSortedArrays(arr2,arr1);

        int size = n + m;

        int left = (size + 1 )/2;

        int low = 0 , high = n;
        while(low<=high){
            int mid1 = low + (high - low) / 2;
            int mid2 = left - mid1;

            int l1 = (mid1>0)?arr1[mid1-1]:INT_MIN;
            int r1 = (mid1<n)?arr1[mid1]:INT_MAX;
            int l2 = (mid2>0)?arr2[mid2-1]:INT_MIN;
            int r2 = (mid2 <m)?arr2[mid2]:INT_MAX;

            if(l1<=r2 && l2<=r1){
                if(size%2==1)return max(l1,l2);
                else return (max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2){
                high = mid1-1;
            }
            else{
                low = mid1 + 1;
            }
        }

        return 0;
    }
};