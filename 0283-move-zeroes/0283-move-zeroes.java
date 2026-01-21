class Solution {

    private void swap(int []nums , int i ,int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }



    public void moveZeroes(int[] nums) {
        int ind = -1;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==0){
                ind = i;
                break;
            }
        }
        if(ind == -1)return;

        for(int i = ind + 1;i<nums.length;i++){
            if(nums[i]!=0){
                swap(nums,i,ind);
                ind++;
            }
        }
    }
}