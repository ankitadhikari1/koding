class KthLargest {
    private:
        int K;
        priority_queue<int,vector<int>,greater<int>>pq;
public:
    KthLargest(int k, vector<int>& nums) {
         K= k;
    for(int i=0;i<nums.size();i++){
        if(pq.size()==k){
            if(pq.top()<nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        else{
            pq.push(nums[i]);
        }
    }
    }
    
    int add(int val) {
         if(pq.size()<K){
        pq.push(val);
        return pq.top();
    }


    if(pq.top()<val){
        pq.pop();
        pq.push(val);
    }
    return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */