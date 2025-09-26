class Solution {
public:

    void merge(int low , int mid , int high , vector<pair<int,int>>&arr , vector<int>&ans){
        int i = low , j = mid + 1;
        vector<pair<int,int>>temp;
        while(i<=mid && j<=high){
            if(arr[i].first>arr[j].first){
                ans[arr[i].second] += (high-j+1);
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                j++;
            }
        }

        while(i<=mid){
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=high){
            temp.push_back(arr[j]);
            j++;
        }

        for(int i=low;i<=high;i++){
            arr[i] = temp[i-low];
        }
    }


    void mergeSort(int low , int high , vector<pair<int,int>>&arr , vector<int>&ans){
        if(low>=high)return;
        int mid = low + (high - low)/2;
        mergeSort(low,mid,arr,ans);
        mergeSort(mid+1,high,arr,ans);
        merge(low,mid,high,arr,ans);
    }


    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        vector<int>ans(n,0);
        mergeSort(0,n-1,arr,ans);
        return ans;
    }
};