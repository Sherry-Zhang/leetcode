class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int i,j = 0;
        for(i = len-2; i>=0; --i)
        {
            if(nums[i+1] > nums[i])  //存在next permutation
                break;
        }
        if(i < 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        for(j = len-1; j > i;--j)
        {
            if(nums[j] > nums[i])
                break;
        }
        swap(nums[i], nums[j]);
        reverse(nums.begin()+i+1, nums.end());
    }
};
