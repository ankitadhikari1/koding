class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st1(nums1.begin(),nums1.end());
        unordered_set<int>st2(nums2.begin(),nums2.end());
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i=0;i<nums1.size();i++){
            if(st2.count(nums1[i])){
                cnt1++;
            }
        }
        for(int i=0;i<nums2.size();i++){
            if(st1.count(nums2[i])){
                cnt2++;
            }
        }

        return {cnt1,cnt2};

    }
};