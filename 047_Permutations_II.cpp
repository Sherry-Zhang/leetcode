//去重复的全排列的解法１：next_permutaion实现
//beats 12.13%
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> >ans;
        int len = nums.size();
        do{
            ans.push_back(nums);
        }while(next_perm(nums,len));
        return ans;
    }
private:
    bool next_perm(vector<int>& nums,int len)
    {
        int i,j;
        for(i = len-2;i>=0;--i)
        {
            if(nums[i] < nums[i+1])
                break;
        }
        if(i < 0)
            return false;
        for(j = len-1;j>=0;--j)
        {
            if(nums[j] > nums[i])
                break;
        }
        swap(nums[j], nums[i]);
        reverse(nums.begin()+i+1,nums.end());
        return true;
    }
};
