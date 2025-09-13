class NumArray {
    vector<int>seg;
    int n;

public:
    NumArray(vector<int>& nums) {
         n = nums.size();
        seg.assign(4*n,0);
        build(0,0,n-1,seg,nums);
    }

    void build(int idx , int low , int high , vector<int>&seg , vector<int>&arr){
        if(low == high){
            seg[idx] = arr[low];
            return ;
        }
        int mid = low + (high - low)/2;
        build(2*idx+1,low,mid,seg,arr);
        build(2*idx+2,mid+1,high,seg,arr);

        seg[idx] = seg[2*idx+1] + seg[2*idx+2];


    }

    void update(int idx , int low , int high , int index , int val ){
        if(low == high){
            seg[idx] = val;
            return;
        }
        int mid = low + (high - low)/2;
        if(index <= mid){
            update(2*idx+1,low,mid,index , val);
        }
        else{
            update(2*idx+2,mid+1,high,index,val);
        }

        seg[idx] = seg[2*idx+1]+seg[2*idx+2];
    }
    
    void update(int index, int val) {
        update(0,0,n-1,index,val);
        
    }
    
    int sumRange(int idx , int low , int high , int l , int r ){
        if(low > r || high < l){
            return 0;
        }
        else if( low >= l && high <= r){
            return seg[idx];
        }
        int mid = low + (high - low)/2;
        return sumRange(2*idx+1,low ,mid,l,r)+sumRange(2*idx+2,mid+1,high,l,r);
    }

    int sumRange(int left, int right) {
        return sumRange(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */